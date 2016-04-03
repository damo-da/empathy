#!/usr/bin/env bash
while true; do
    read -p "Do you wish to clean Empathy? Any untracked file in git will be reomved.Y/N" yn
    case $yn in
        [Yy]* ) git clean -d -f -x;break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done

echo "Everything done!"
