# underlyingGit

## ObjectTypes
Git is a content-addressable filesystem. All the core data are 
stored in system as one object of speicific types in folder `.git/ojbects`.
There are four types of basic objects in git system: 
* blob
* tree
* commit
* tag

see `ObjectType.hpp` for the four enum defination.

All the objects are indexed by git system via a globally unique `SHA1` key. We can use command 
`git cat-file` to read the contents or type of them.

1. use `git cat-file -p` to read the contents of one object
```
$ git cat-file -p d670460b4b4aece5915caf5c68d12f560a9fe3e4
test content
```

2. use `git cat-file -t` to get the object type
```
$ git cat-file -t 1f7a7a472abf3dd9643fd615f6da379c4acb3e3a
blob
```

## The SHA1 key
Since every objects in .git database has its own `SHA1` key, the key is one of the most important
concept in git system because it is this hash value which orginize all the objects together to endusers.

The `SHA1` key is a 40-charactor checksum hash -- a hash of the content you're storing plus a header.
In git, this `SHA1` key is splitted into two parts:
+ 2 charator as directory name
+ 38 charactor as object file name

For example, an Object with `SHA1` key == d670460b4b4aece5915caf5c68d12f560a9fe3e4 will be 
located in dir `.git/objects/d6` with filename truncated as 70460b4b4aece5915caf5c68d12f560a9fe3e4.
```
$ find .git/objects -type f
.git/objects/d6/70460b4b4aece5915caf5c68d12f560a9fe3e4
```

### blob object
A `blob` object stores pure content of one file, which means the file name and directory information
is not stored in such objects(`tree` ojbect).

### tree object

### commit object

# Ref
[Pro Git Book](https://git-scm.com/book/en/v2/)