DYNGO
=====

I like when I can log into my notebook via ssh using some easily
remembered name. 

But it is not always a case in the world of NATs and VPNs.

If machine always have public IP address, than using some dynamic DNS
service may help (short of necessity to use full domain name. But 
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

PRROTOCOL
=========

**dyngo** uses protocol compatible with dyndns.org, as described 
pn [help.dyn.com](https://help.dyn.com/remote-access-api/perform-update/
)
As different dynamic DNS servers use different path components of URL,
you should specify URL with path component (up to question mark) in 
the *server* parameter of configuraton section.

INSTALLATION
============

**dyngo** is simple script which doesn't require anything but
python3 with standard library and **ip** utility from iproute (or
iproute2 on Debian) package, which presents on every modern Linux
system.

I've even preferred to use
[urllib](https://docs.python.org/3/library/urllib.request.html#module-urllib.request)
to [requests](http://docs.python-requests.org/) to eliminate extra
external dependency.

So, you can just drop **dyngo** somewhere in your filesystem, say in 
**/usr/local/sbin** and put config into */etc* But **dyngo** should run
as a service, so you might want to use provided service file.

**dyngo** should run as unprivileged user. But its configuration file
should, readable for this user, contains somewhat sensitive information
—  your dyndns passwords. So, don't use common account many untrusted
code run as such as **nobody** or **www-data**. Better to create special
user dyngo.

There should be writable directory, writable for this user for
persistent state database. By default it is /var/lib/dyngo.


