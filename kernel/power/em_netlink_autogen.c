// SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause)
/* Do not edit directly, auto-generated from: */
/*	Documentation/netlink/specs/dev-energy-model.yaml */
/* YNL-GEN kernel source */
/* To regenerate run: tools/net/ynl/ynl-regen.sh */

#include <net/netlink.h>
#include <net/genetlink.h>

#include "em_netlink_autogen.h"

#include <uapi/linux/dev_energy_model.h>

/* DEV_ENERGY_MODEL_CMD_GET_PERF_TABLE - do */
static const struct nla_policy dev_energy_model_get_perf_table_nl_policy[DEV_ENERGY_MODEL_A_PERF_TABLE_PERF_DOMAIN_ID + 1] = {
	[DEV_ENERGY_MODEL_A_PERF_TABLE_PERF_DOMAIN_ID] = { .type = NLA_U32, },
};

/* Ops table for dev_energy_model */
static const struct genl_split_ops dev_energy_model_nl_ops[] = {
	{
		.cmd	= DEV_ENERGY_MODEL_CMD_GET_PERF_DOMAINS,
		.doit	= dev_energy_model_nl_get_perf_domains_doit,
		.flags	= GENL_CMD_CAP_DO,
	},
	{
		.cmd		= DEV_ENERGY_MODEL_CMD_GET_PERF_TABLE,
		.doit		= dev_energy_model_nl_get_perf_table_doit,
		.policy		= dev_energy_model_get_perf_table_nl_policy,
		.maxattr	= DEV_ENERGY_MODEL_A_PERF_TABLE_PERF_DOMAIN_ID,
		.flags		= GENL_CMD_CAP_DO,
	},
};

static const struct genl_multicast_group dev_energy_model_nl_mcgrps[] = {
	[DEV_ENERGY_MODEL_NLGRP_EVENT] = { "event", },
};

struct genl_family dev_energy_model_nl_family __ro_after_init = {
	.name		= DEV_ENERGY_MODEL_FAMILY_NAME,
	.version	= DEV_ENERGY_MODEL_FAMILY_VERSION,
	.netnsok	= true,
	.parallel_ops	= true,
	.module		= THIS_MODULE,
	.split_ops	= dev_energy_model_nl_ops,
	.n_split_ops	= ARRAY_SIZE(dev_energy_model_nl_ops),
	.mcgrps		= dev_energy_model_nl_mcgrps,
	.n_mcgrps	= ARRAY_SIZE(dev_energy_model_nl_mcgrps),
};
