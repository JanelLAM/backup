#!/bin/bash

mkdir /tmp/scripts
cd /tmp/scripts
cp -r /etc/pam.d /tmp/scripts
mv pam.d test
chown -R redhat test
chmod -R 700 test
