*   if no add waitpid:
```
$ ps -aux | grep zombie
```
coheren+ 25534  0.0  0.0   4076   440 pts/90   S+   02:41   0:00 ./zombie
coheren+ 25535  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 25595  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 25650  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 25702  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 25756  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 25838  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 25899  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 25980  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 26059  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 26117  0.0  0.0      0     0 pts/90   Z+   02:41   0:00 [zombie] <defunct>
coheren+ 26175  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26249  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26327  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26394  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26466  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26547  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26623  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26703  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26791  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26887  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 26979  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 27073  0.0  0.0      0     0 pts/90   Z+   02:42   0:00 [zombie] <defunct>
coheren+ 27080  0.0  0.0 112688   968 pts/4    S+   02:42   0:00 grep --color=auto zombie