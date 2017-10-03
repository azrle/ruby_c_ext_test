# Build
```
$ cd ext/bar
$ ruby extconf.rb
$ make
```

# Test result
```
$ ruby -Iext -rbar/bar -e 'f=[]; 100000.times {f<<"foo"}; b=Bar.new; p b.bar_good, b.bar_bad;'
"bar"
"foo"
```

Note: 
* `bar_bad` is initialized as "bar"; however it prints "foo";
* `bar_bad` probably causes segmentation fault instead of printing "foo".

Tested ruby versions:
* ruby 2.3.1p112 (2016-04-26 revision 54768) [x86_64-linux]
* ruby 2.4.0p0 (2016-12-24 revision 57164) [x86_64-linux]
