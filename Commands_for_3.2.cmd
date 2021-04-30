3.2.i
 
$ ls –l | more
$ sort /etc/passwd | uniq
$ cat /etc/group | head -7 | tail -5 
$ ls -l | find ./ -type f -name "*.txt" -exec grep "program" {} \;
$ cat /etc/passwd | grep “name" | tee file2.txt | wc –l
$ ifconfig | awk '{match($0,/[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+/); ip = substr($0,RSTART,RLENGTH); print ip}'


3.2.ii

$ man ifconfig | grep -n "down" | wc -l

command explanation:
man ifconfig == to open up the ifconfig manual page
grep -n      == to find and take a line of keyword "down"
wc           == word count match with the times where the keyword "down" been found from ifconfig manual page
