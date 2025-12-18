/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause) */
/* Do not edit directly, auto-generated from: */
/*	Documentation/netlink/specs/device-energy-model.yaml */
/* YNL-GEN kernel header */
/* To regenerate run: tools/net/ynl/ynl-regen.sh */

#ifndef _LINUX_DEVICE_ENERGY_MODEL_GEN_H
#define _LINUX_DEVICE_ENERGY_MODEL_GEN_H

#include <net/netlink.h>
#include <net/genetlink.h>

#include <uapi/linux/device_energy_model.h>

int device_energy_model_nl_get_perf_domains_doit(struct sk_buff *skb,
						 struct genl_info *info);
int device_energy_model_nl_get_perf_domains_dumpit(struct sk_buff *skb,
						   struct netlink_callback *cb);
int device_energy_model_nl_get_perf_table_doit(struct sk_buff *skb,
					       struct genl_info *info);

enum {
	DEVICE_ENERGY_MODEL_NLGRP_EVENT,
};

extern struct genl_family device_energy_model_nl_family;

#endif /* _LINUX_DEVICE_ENERGY_MODEL_GEN_H */
