DYNGO
=====

I like when I can log into my notebook via ssh using some easily
remembered name. 

But it is not always a case in the world of NATs and VPNs.

If machine always have public IP address, than using some dynamic DNS
service may help (short of neccessity to use full domain name. But 
${HOME}/.ssh/config may help). But what if you log into your office
workstation via corporate VPN, and want ssh back home?

If you have enough power to run (or persuade system administrator to
run) dyndns service in your office network, dyndns can help even there.

But your setup need to know different dyndns servers depending on IP
address.

So, I wrote  DYNGO is dynamic DNS client which can handle lots of
dynamic DNS servers simultaneously. It reads config file, which
specifies which network ranges correspond to which server, and
then runs as a daemon, periodically polling IP addresses of all
interfaces of the machine. If it finds change, it makes http(s) request
to specified URL.

See [manual page](dyngo.md) for more info.



