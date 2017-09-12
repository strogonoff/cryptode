#ifndef __RVC_H__
#define __RVC_H__

#define RVC_USE_MAIN				1

/*
 * VPN profile type
 */

enum RVC_VPN_PROFILE_TYPE {
	RVC_VPN_PROFILE_OVPN = 0,		/* OpenVPN profile */
	RVC_VPN_PROFILE_TBLK			/* TunnelBlick profile */
};

/** List all VPN connections.
 *
 * Note that the allocated memory for listing VPN connections should be freed
 * after used.
 * 
 * @param [out] connections JSON buffer which keeps connection list.
 * @return 0 If success, otherwise non-zero will be returned.
 */

int rvc_list_connections(char **connections);

/** Try to connect to RVC VPN server
 *
 * The JSON buffer to be returned may have two types, single or array JSON buffer
 * by connection name.
 * 
 * Note that the allocated memory for connection status should be freed
 * after used.
 * 
 * @param [in] name 'all' or VPN connection name to be connected
 * @param [out] conn_status JSON buffer which keeps connection status
 *			    for given connection name.
 * @return 0 If success, otherwise non-zero will be returned.
 */

int rvc_connect(const char *name, char **conn_status);

/** Try to disconnect from RVC VPN server
 *
 * The JSON buffer to be returned may have two types, single or array JSON buffer
 * by connection name.
 * 
 * Note that the allocated memory for connection status should be freed
 * after used.
 * 
 * @param [in] name 'all' or VPN connection name to be disconnected
 * @param [out] conn_status buffer which keeps connection status for given connection name.
 * @return 0 If success, otherwise non-zero will be returned.
 */

int rvc_disconnect(const char *name, char **conn_status);

/** Get connection status
 *
 * The JSON buffer to be returned may have two types, single or array JSON buffer
 * by connection name.
 * 
 * Note that the allocated memory for connection status should be freed
 * after used.
 * 
 * @param [in] name 'all' or VPN connection name to be disconnected
 * @param [out] conn_status buffer which keeps connection status for given connection name.
 * @return 0 If success, otherwise non-zero will be returned.
 */

int rvc_get_status(const char *name, char **conn_status);

/** Reload RVD VPN connections
 *
 * This function requires sudo privilege, so it needs to gain root privilege before calling.
 * 
 * @return 0 If success, otherwise non-zero will be returned.
 */

int rvc_reload();

/** Import OpenVPN or TunnelBlick VPN profile
 *
 * This function requires sudo privilege, so it needs to gain root privilege before calling.
 * After imported VPN profiles, then this function will reload VPN connections automatically.
 *
 * @param [in] import_type type of VPN profile to be imported.
 * @param [in] import_path path of VPN profile to be imported.
 * 
 * @return 0 If success, otherwise non-zero will be returned.
 */

int rvc_import(int import_type, const char *import_path);

#endif /* __RVC_H__ */