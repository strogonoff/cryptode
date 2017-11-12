#ifndef __RVD_CONF_H__
#define __RVD_CONF_H__

#define OVPN_CONFIG_EXTENSION			".ovpn"
#define RVC_CONFIG_EXTENSION			".json"

#define MIN_PRE_EXEC_INTERVAL			1
#define MAX_PRE_EXEC_INTERVAL			60

/*
 * RVC configuration structure
 */

struct rvc_vpn_config {
	char name[RVD_MAX_CONN_NAME_LEN + 1];
	char ovpn_profile_path[RVD_MAX_PATH];
	char ovpn_log_path[RVD_MAX_PATH];

	bool auto_connect;

	uid_t pre_exec_uid;
	char pre_exec_cmd[512];

	int pre_exec_interval;					/* pre exec command interval in seconds */
	time_t pre_exec_ts;						/* timestamp of pre-exec-cmd */

	int pre_exec_status;
};

/*
 * parse RVC configuration file
 */

int rvc_read_vpn_config(const char *conf_dir, const char *config_name, struct rvc_vpn_config *vpn_config);

/*
 * write RVC configuration file
 */

int rvc_write_vpn_config(const char *config_dir, const char *config_name, struct rvc_vpn_config *vpn_config);

#endif /* __RVD_CONF_H__ */