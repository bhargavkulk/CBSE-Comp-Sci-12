# File Handling
Collection of some important file handling questions that are asked a lot in the exam

## Index:
* File Handling
  * Binary Files
    * Appending to a file
    * Deleting a record from a file
    * Inserting into a file
    * Modifying a record in a file
    * Searching for a record in a file
    * Sorting the contents of a file

## fstream flags:
Below is a table of all the flags that specify a mode for a file stream

flag | action
---- | ------
ios::in | opens fstream in input mode i.e. you can **only read** from the file
ios::out | opens fstream in output mode i.e you can **only write** into the file
ios::binary | opens fstream in binary mode i.e. operations are performed in **binary** rather than text
ios::ate | the **output position** starts **at the end** of the file.
ios::ape | all output operations happen **at the end** of the file, **appending** to its existing contents. unlike ios::ate, you can't move backwards
ios::create | if the file is a **new file**, the operation fails because it **cannot create a new file**. if the file already exists, then it is opened and its content is made available for processing
ios::noreplace | if the file **already exists** and you try to open it, this operation would fail because it cannot create a file of the same name in the same location. if the file is a new file, then it gets created. 
