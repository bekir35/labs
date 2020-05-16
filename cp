#!/bin/bash
#BekirKILIC


echo -e   "alias eth12 bonding\noptions eth12 mode=4 miimon=100" > /etc/modprobe.d/bonding.conf
cp -a /etc/sysconfig/network-scripts/ifcfg-eth1  /etc/sysconfig/network-scripts/ifcfg-eth12
cp -a /etc/sysconfig/network-scripts/ifcfg-eth1  /etc/sysconfig/network-scripts/ifcfg-eth2

sed -i 's/DEVICE=eth1/DEVICE=eth12/g' /etc/sysconfig/network-scripts/ifcfg-eth12

sed -i '/IPADDR/d' /etc/sysconfig/network-scripts/ifcfg-eth1
sed -i '/IPADDR/d' /etc/sysconfig/network-scripts/ifcfg-eth1
sed -i '/NETMASK/d' /etc/sysconfig/network-scripts/ifcfg-eth2
sed -i '/NETMASK/d' /etc/sysconfig/network-scripts/ifcfg-eth2

sed -i 's/DEVICE=eth1/DEVICE=eth2/g' /etc/sysconfig/network-scripts/ifcfg-eth2
echo -e   "SLAVE=yes\nMASTER=eth12" >> /etc/sysconfig/network-scripts/ifcfg-eth1
echo -e   "SLAVE=yes\nMASTER=eth12" >> /etc/sysconfig/network-scripts/ifcfg-eth2
