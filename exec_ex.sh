#!/bin/bash

echo $$ #$$:自身のPID
sleep 30

exec sleep 100 #ここでプロセスがsleepに置き換わる

echo "hoge" #ここには来ない
