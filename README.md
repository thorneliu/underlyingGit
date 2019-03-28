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
A `tree` object contains the structual file and directory information of files in the repository.
The contents of one `tree` object is a list of objects:
- `tree` refers to subdirectory under this tree
- `blob` refers to files in this directory

For example, given a tree object `ea8b8dea81f889d48f00b2164fb18936d406c40a`
```
$ git cat-file -p ea8b
100644 blob 262957e98aa825a31b7f0412f730758c03984ad2    CMakeList.txt
040000 tree cb84fc68f806c3deb2ae3e0792190a751ef16043    src
```

And the tree object `cb84fc68f806c3deb2ae3e0792190a751ef16043` is one subdirectory in this folder,
with its contents as:
```
$ git cat-file -p cb84fc68f806c3deb2ae3e0792190a751ef16043
100644 blob 9054cbb8f672568e722775ef0a9f236111700bc5    hello.c
100644 blob a4b43ca1606cbb9710eef4378d8712eae7628f6d    hello.h
```

So the whole tree structure shows a file hierarchy as following:
```
$ tree
.
├── CMakeList.txt
└── src
    ├── hello.c
    └── hello.h
```

In `git` source code, the `tree` object is presented as struct tree:
```
struct tree {
	struct object object;
	struct tree_entry_list *entries;
};
```
where the `tree_entry_list` is one node of double-linked list with defination:
```
struct tree_entry_list {
	struct tree_entry_list *next;
	unsigned directory : 1;
	unsigned executable : 1;
	unsigned symlink : 1;
	unsigned int mode;
	char *name;
	union {
		struct tree *tree;
		struct blob *blob;
	} item;
	struct tree_entry_list *parent;
};
```

The `tree_entry_list` is a double-linked list to present one tree object in git system, where the `next`

### commit object

### sha1_file.c
git仓库里面的sha1_file.c提供了读写object的基本方法：
- 根据内容计算sha1的值
- 计算sha1 filename
- read_sha1_file 可以在给定sha1值的情况下将文件的内容解析出来
- write_sha1_file 可以通过在制定文件buffer的情况下，计算sha1值并将buffer + header压缩后写入对应filename的文件中

# Ref
[Pro Git Book](https://git-scm.com/book/en/v2/)
