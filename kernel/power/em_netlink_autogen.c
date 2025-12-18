// SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-3-Clause)
/* Do not edit directly, auto-generated from: */
/*	Documentation/netlink/specs/device-energy-model.yaml */
/* YNL-GEN kernel source */
/* To regenerate run: tools/net/ynl/ynl-regen.sh */

#include <net/netlink.h>
#include <net/genetlink.h>

#include "em_netlink_autogen.h"

#include <uapi/linux/device_energy_model.h>

/* DEVICE_ENERGY_MODEL_CMD_GET_PERF_DOMAINS - do */
static const struct nla_policy device_energy_model_get_perf_domains_nl_policy[DEVICE_ENERGY_MODEL_A_PERF_DOMAINS_PERF_DOMAIN_ID + 1] = {
	[DEVICE_ENERGY_MODEL_A_PERF_DOMAINS_PERF_DOMAIN_ID] = { .type = NLA_U32, },
};

/* DEVICE_ENERGY_MODEL_CMD_GET_PERF_TABLE - do */
static const struct nla_policy device_energy_model_get_perf_table_nl_policy[DEVICE_ENERGY_MODEL_A_PERF_TABLE_PERF_DOMAIN_ID + 1] = {
	[DEVICE_ENERGY_MODEL_A_PERF_TABLE_PERF_DOMAIN_ID] = { .type = NLA_U32, },
};

/* Ops table for device_energy_model */
static const struct genl_split_ops device_energy_model_nl_ops[] = {
	{
		.cmd		= DEVICE_ENERGY_MODEL_CMD_GET_PERF_DOMAINS,
		.doit		= device_energy_model_nl_get_perf_domains_doit,
		.policy		= device_energy_model_get_perf_domains_nl_policy,
		.maxattr	= DEVICE_ENERGY_MODEL_A_PERF_DOMAINS_PERF_DOMAIN_ID,
		.flags		= GENL_CMD_CAP_DO,
	},
	{
		.cmd	= DEVICE_ENERGY_MODEL_CMD_GET_PERF_DOMAINS,
		.dumpit	= device_energy_model_nl_get_perf_domains_dumpit,
		.flags	= GENL_CMD_CAP_DUMP,
	},
	{
		.cmd		= DEVICE_ENERGY_MODEL_CMD_GET_PERF_TABLE,
		.doit		= device_energy_model_nl_get_perf_table_doit,
		.policy		= device_energy_model_get_perf_table_nl_policy,
		.maxattr	= DEVICE_ENERGY_MODEL_A_PERF_TABLE_PERF_DOMAIN_ID,
		.flags		= GENL_CMD_CAP_DO,
	},
};

static const struct genl_multicast_group device_energy_model_nl_mcgrps[] = {
	[DEVICE_ENERGY_MODEL_NLGRP_EVENT] = { "event", },
};

struct genl_family device_energy_model_nl_family __ro_after_init = {
	.name		= DEVICE_ENERGY_MODEL_FAMILY_NAME,
	.version	= DEVICE_ENERGY_MODEL_FAMILY_VERSION,
	.netnsok	= true,
	.parallel_ops	= true,
	.module		= THIS_MODULE,
	.split_ops	= device_energy_model_nl_ops,
	.n_split_ops	= ARRAY_SIZE(device_energy_model_nl_ops),
	.mcgrps		= device_energy_model_nl_mcgrps,
	.n_mcgrps	= ARRAY_SIZE(device_energy_model_nl_mcgrps),
};
