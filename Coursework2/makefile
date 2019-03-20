test: 
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c test.cpp
	link test.obj BST.lib
	test
	
app: 
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c myApp.cpp
	link myApp.obj BST.lib
	myApp