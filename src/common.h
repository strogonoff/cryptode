#ifndef __RVD_COMMON_H__
#define __RVD_COMMON_H__

#include <netinet/in.h>

/* macro constants */

#define RVD_MAX_PATH               256
#define RVD_MAX_FILE_NAME          256
#define RVD_MAX_LINE               512
#define RVD_MAX_LOGMSG_LEN         1024
#define RVD_MAX_CMD_LEN            2048
#define RVD_MAX_RESP_LEN           4096
#define RVD_MAX_CONN_NAME_LEN      128
#define RVD_MAX_CONN_INFO_LEN      2048
#define RVD_MAX_CONN_STATUS_LEN    2048
#define RVD_BUF_SIZE               512
#define RVD_MAX_IPADDR_LEN         INET6_ADDRSTRLEN
#define RVD_MAX_HNAME_LEN          128
#define RVD_MAX_PORTSTR_LEN        16
#define RVD_MAX_PROTOSTR_LEN       16
#define RVD_MAX_DATETIME_LEN       128

#define RVC_MAX_IMPORT_SIZE        10240

/* copyright message */
#define RVC_COPYRIGHT_MSG          "Copyright 2017 Ribose Inc <https://www.ribose.com>"

/* default RVD configuration path */
#define RVD_DEFAULT_CONFIG         "/opt/rvc/etc/rvd.conf"

/* rvd default command listen socket path */
#define RVD_LISTEN_SOCK_PATH       "/var/run/rvd.sock"

/* rvd default log file path */
#define RVD_DEFAULT_LOGDIR_PATH    "/var/log/rvd"

/* rvd default UID for writting to rvd socket */
#define RVD_DEFAULT_UID            501

/* rvd pid file path */
#define RVD_PID_DPATH              "/var/run/rvd"
#define RVD_PID_FPATH              "/var/run/rvd/rvd.pid"

/* rvd command codes */
enum RVD_CMD_CODE {
	RVD_CMD_CONNECT,
	RVD_CMD_DISCONNECT,
	RVD_CMD_RECONNECT,
	RVD_CMD_STATUS,
	RVD_CMD_SCRIPT_SECURITY,
	RVD_CMD_RELOAD,
	RVD_CMD_IMPORT,
	RVD_CMD_EDIT,
	RVD_CMD_REMOVE,
	RVD_CMD_DNS_OVERRIDE,
	RVD_CMD_GET_CONFDIR,
	RVD_CMD_UNKNOWN
};

/* rvd command response codes */
enum RVD_RESP_CODE
{
	RVD_RESP_OK = 0,
	RVD_RESP_INVALID_CMD,
	RVD_RESP_SOCK_CONN,
	RVD_RESP_JSON_INVALID,
	RVD_RESP_NO_MEMORY,
	RVD_RESP_SUDO_REQUIRED,
	RVD_RESP_RVD_NOT_RUNNING,
	RVD_RESP_SEND_SIG,
	RVD_RESP_INVALID_PROFILE_TYPE,
	RVD_RESP_INVALID_CONF_DIR,
	RVD_RESP_IMPORT_TOO_LARGE,
	RVD_RESP_IMPORT_EXIST_PROFILE,
	RVD_RESP_EMPTY_LIST,
	RVD_RESP_WRONG_PERMISSION,
	RVD_RESP_CONN_NOT_FOUND,
	RVD_RESP_CONN_ALREADY_CONNECTED,
	RVD_RESP_CONN_ALREADY_DISCONNECTED,
	RVD_RESP_CONN_IN_PROGRESS,
	RVD_RESP_NO_EXIST_DNS_UTIL,
	RVD_RESP_ERR_DNS_UTIL,
	RVD_RESP_ERR_WRONG_RVC_PATH,
	RVD_RESP_ERR_NOT_FOUND_VPNCONF,
	RVD_RESP_ERR_VPNCONF_OPT_TYPE,
	RVD_RESP_ERR_VPNCONF_OPT_VAL,
	RVD_RESP_ERR_INVALID_OVPN_BIN,
	RVD_RESP_UNKNOWN_ERR,
};

/* VPN connection state */
enum RVD_VPNCONN_STATE {
	RVD_CONN_STATE_DISCONNECTED = 0,
	RVD_CONN_STATE_CONNECTED,
	RVD_CONN_STATE_CONNECTING,
	RVD_CONN_STATE_DISCONNECTING,
	RVD_CONN_STATE_RECONNECTING,
	RVD_CONN_STATE_UNKNOWN
};

#endif /* __RVD_COMMON_H__ */
