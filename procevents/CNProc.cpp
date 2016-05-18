#include <sys/socket.h>
#include <linux/connector.h>
#include <linux/netlink.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include <iostream>
#include <atomic>

#include "CNProc.h"

using namespace std;

namespace CNProc {

    static int nl_sock = -1;

    static std::atomic_bool running(false);

    bool connect() {
        nl_sock = socket(PF_NETLINK,SOCK_DGRAM,NETLINK_CONNECTOR);
        if (nl_sock == -1) {
            cerr << __func__ << "() - socket() - " << strerror(errno) << endl;
            return false;
        }

        struct sockaddr_nl sa_nl;
        sa_nl.nl_family = AF_NETLINK;
        sa_nl.nl_groups = CN_IDX_PROC;
        sa_nl.nl_pid = getpid();

        int rc = bind(nl_sock, (struct sockaddr *)&sa_nl, sizeof(sa_nl));
        if (rc == -1) {
            cerr << __func__ << "() - bind() - " << strerror(errno) << endl;
            return false;
        }

        return true;
    }

    bool subscribe() {
        if (nl_sock == -1) {
            cerr << __func__ << "() - no socket" << endl;
            return false;
        }

        struct __attribute__ ((aligned(NLMSG_ALIGNTO))) {
            struct nlmsghdr nl_hdr;
            struct __attribute__ ((__packed__)) {
                struct cn_msg cn_msg;
                enum proc_cn_mcast_op cn_mcast;
            };
        } nlcn_msg;

        memset(&nlcn_msg, 0, sizeof(nlcn_msg));

        nlcn_msg.nl_hdr.nlmsg_len = sizeof(nlcn_msg);
        nlcn_msg.nl_hdr.nlmsg_pid = getpid();
        nlcn_msg.nl_hdr.nlmsg_type = NLMSG_DONE;

        nlcn_msg.cn_msg.id.idx = CN_IDX_PROC;
        nlcn_msg.cn_msg.id.val = CN_VAL_PROC;
        nlcn_msg.cn_msg.len = sizeof(enum proc_cn_mcast_op);

        nlcn_msg.cn_mcast = PROC_CN_MCAST_LISTEN;

        int rc = send(nl_sock, &nlcn_msg, sizeof(nlcn_msg), 0);
        if (rc == -1) {
            cerr << __func__ << "() - send() - " << strerror(errno) << endl;
            return false;
        }

        return true;
    }

    bool process(std::function<void(const struct proc_event&)>& lambda) {
        if (nl_sock == -1) {
            cerr << __func__ << "() - no socket" << endl;
            return false;
        }
        struct __attribute__ ((aligned(NLMSG_ALIGNTO))) {
            struct nlmsghdr nl_hdr;
            struct __attribute__ ((__packed__)) {
                struct cn_msg cn_msg;
                struct proc_event proc_ev;
            };
        } nlcn_msg;
        running.store(true);
        while (running) {
            int rc = recv(nl_sock, &nlcn_msg, sizeof(nlcn_msg), 0);
            if (rc == 0) {
                cerr << __func__ << "() - recv() - no data" << endl;
                running.store(false);
                return false;
            } else if (rc == -1) {
                cerr << __func__ << "() - send() - " << strerror(errno) << endl;
                running.store(false);
                return false;
            }
            lambda(nlcn_msg.proc_ev);
        }
        running.store(false);
        return true;
    }

    void stop() {
        running.store(false);
    }
}
