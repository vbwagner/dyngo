% dingo(8)
% Victor Wagner <vitus@wagner.pp.ru>
% September 2019

NAME
====

dingo - multi-network dynamic DNS client

SYNOPSIS
========

**dyngo** [ **-f** *configuration-file* ]

DESCRIPTION
===========

**dyngo** is dynamic DNS client which periodically tries to check if
some of IP addresses of the current machine change and report to
appropriate dynamic DNS server if so.

It is primarily intended to let machine be visible in the local DNS 
of office or home local networks, VPNs and so on. So it expects that
there could be private dynamic DNS servers. Couple of dynamic DNS
scripts is included into distribution to make it easier to set up
dynamic DNS.

But nothing prevent user from defining some of networks as global
ones and put URL of public dyndns server into it.

If network is defined as global, i.e have netmask /0, private ip ranges
wouldn't be reported to corresponding DNS server.

CONFIGURATION FILE
==================

Configuration file **dyngo.conf** is ini-style file. It contains section
**dyngo** with global service parameters and section per dyndns server.

Names of server-description sections are arbitrary, but should be
unique, because they are used as keys into persistent database.

Parameters of **dyngo** section
-------------------------------

* interval - number of seconds between rescans of network interfaces
* database - path to persistent state database
* ca - path to trusted certificate store in openssl compatible format.
* loglevel - minimum log message level which shoud to console

Parameters of network section
-----------------------------

* **hostname** - fully qualified domain name of your host to register in DNS
* **network** - network in *address*/*bits* notation which this host
should belong to. If we see address from this network on one of our
interfaces, we would send request to  corresponding server. If net is
not privatte, but include private ranges, i.e. 0.0.0.0/0 or ::/0 private
addresses are not considered part of it.
* **server** - full url (without query string) of the dyndns web  handler.
* **user** - user name for HTTP basic authentication
* **password** - password for HTTP basic authentcircation


