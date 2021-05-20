/*
 * Copyright (C) 2021 Mellanox Technologies, Ltd. ALL RIGHTS RESERVED.
 *
 * This software product is a proprietary product of Mellanox Technologies Ltd.
 * (the "Company") and all right, title, and interest in and to the software
 * product, including all associated intellectual property rights, are and
 * shall remain exclusively with the Company.
 *
 * This software product is governed by the End User License Agreement
 * provided with the software product.
 *
 */

#ifndef _DOCA_FLOW_CHAIN_H_
#define _DOCA_FLOW_CHAIN_H_

#include "doca_flow.h"

struct doca_flow_port;
struct doca_flow_pipe;

enum DOCA_FLOW_CHAIN_FLAGS {
    DOCA_FLOW_CHAIN_ISOLATE_MODE = 1 << 0,
    DOCA_FLOW_CHAIN_ACL          = 1 << 1,
    DOCA_FLOW_CHAIN_PIPE         = 1 << 2,
};

/**
 * @brief - init chain.
 * @param flags
 *    DOCA_FLOW_CHAIN_ISOLATE_MODE - by default all
 *     traffic is directed to kernel represntor. user
 *     should add pass/drop rules. pass rules will
 *     get to pipe
 *    DOCA_FLOW_CHAIN_ACL - new packets not known
 *    to fast-path will go through ACL.
 *    ACL is configured thourgh doca_flow_acl api.
 *
 * @return 
 */
int doca_flow_chain_init(int flags);

/**
 * @brief - if chain configured in isolate mode,
 *  on default all traffic go to kernel represntor.
 *  isolate mode allow drop rules, and pass rules.
 *  packet that don't hit any of them will reach 
 *  the kernel.
 *
 * @param m
 * @param mask
 *
 * @return 
 */
int doca_flow_isolate_drop(struct doca_flow_port *port,
                           struct doca_flow_match *m,
                           struct doca_flow_match *mask);


/**
 * @brief - if chain configured in isolate mode,
 *  on default all traffic go to kernel represntor.
 *  isolate mode allow drop rules, and pass rules.
 *  packet that don't hit any of them will reach 
 *  the kernel.
 *
 * @param m
 * @param mask
 * @param action 
 *
 * @return 
 */
int doca_flow_isolate_pass(struct doca_flow_port *port,
                           struct doca_flow_match *m,
                           struct doca_flow_match *mask,
                           struct doca_flow_actions *action);

/**
 * @brief - remove all flows.
 *
 * @return 
 */
int doca_flow_isolate_clean_all(void);



#endif
