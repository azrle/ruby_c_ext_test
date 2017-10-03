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
