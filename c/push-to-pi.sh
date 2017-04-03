#!/bin/sh

sftp pi@192.168.1.14 <<EOT
put -r ./* playing-the-air/
bye
EOT
