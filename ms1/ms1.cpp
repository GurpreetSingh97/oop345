Script started on Wed 21 Mar 2018 01:52:46 AM EDT
gsingh520@matrix:~/oop345/ms1> whoami
gsingh520
gsingh520@matrix:~/oop345/ms1> g++ main.cpp Task.cpp Utilities.cpp -std=c++0x -o m s1
gsingh520@matrix:~/oop345/ms1> ms1 FileWithMalformedRecords.txt '|'
Command Line Arguments
----------------------
Tasks File Specified          = FileWithMalformedRecords.txt
File Record Field Delimiter   = |


*** Load and Accept the Tasks ***

List of Accepted Tasks
----------------------
Task Name    : [Power Supply]      [4]
 Continue to : [Motherboard]        *** to be validated ***
Task Name    : [Motherboard]       [3]
 Continue to : [CPU]                *** to be validated ***
 Redirect to : [Remove CPU]         *** to be validated ***
Task Name    : [Remove CPU]        [1]
 Continue to : [CPU]                *** to be validated ***
Task Name    : [CPU]               [5]
 Continue to : [Memory]             *** to be validated ***
 Redirect to : [Remove CPU]         *** to be validated ***
Task Name    : [Remove CPU]        [1]
 Continue to : [CPU]                *** to be validated ***
Task Name    : [Memory]            [4]
 Continue to : [SSD]                *** to be validated ***
 Redirect to : [Remove Memory]      *** to be validated ***
Task Name    : [Remove Memory]     [1]
 Continue to : [Memory]             *** to be validated ***
Task Name    : [SSD]               [4]
 Continue to : [GPU]                *** to be validated ***
 Redirect to : [Remove SSD]         *** to be validated ***
Task Name    : [Remove SSD]        [1]
 Continue to : [SSD]                *** to be validated ***
Task Name    : [GPU]               [3]
 Continue to : [Test]               *** to be validated ***
Task Name    : [Test]              [4]
 Continue to : [Approve]            *** to be validated ***
 Redirect to : [Repair]             *** to be validated ***
Task Name    : [Test / 4 / Approve / Repair][1]
Task Name    : [CPU]               [5]
 Continue to : [Memory]             *** to be validated ***
 Redirect to : [Remove CPU]         *** to be validated ***
Task Name    : [4]                 [SSD]
 Continue to : [GPU]                *** to be validated ***
 Redirect to : [Remove SSD]         *** to be validated ***
Task Name    : [Repair]            [1]
Task Name    : [Approve]           [1]

Check Follow-On Tasks
---------------------
*** Validate [Motherboard] @ [Power Supply] ***
*** Validate [CPU] @ [Motherboard] ***
*** Validate [CPU] @ [Remove CPU] ***
*** Validate [Memory] @ [CPU] ***
*** Further checks suspended ***

Validating the Accepted Tasks
-----------------------------
Task Name    : [Power Supply]      [4]
 Continue to : [Motherboard]       
Task Name    : [Motherboard]       [3]
 Continue to : [CPU]               
 Redirect to : [Remove CPU]        
Task Name    : [Remove CPU]        [1]
 Continue to : [CPU]               
Task Name    : [CPU]               [5]
 Continue to : [Memory]            
 Redirect to : [Remove CPU]        
Task Name    : [Remove CPU]        [1]
 Continue to : [CPU]               
Task Name    : [Memory]            [4]
 Continue to : [SSD]               
 Redirect to : [Remove Memory]     
Task Name    : [Remove Memory]     [1]
 Continue to : [Memory]            
Task Name    : [SSD]               [4]
 Continue to : [GPU]               
 Redirect to : [Remove SSD]        
Task Name    : [Remove SSD]        [1]
 Continue to : [SSD]               
Task Name    : [GPU]               [3]
 Continue to : [Test]              
Task Name    : [Test]              [4]
 Continue to : [Approve]           
 Redirect to : [Repair]            
Task Name    : [Test / 4 / Approve / Repair][1]
Task Name    : [CPU]               [5]
 Continue to : [Memory]            
 Redirect to : [Remove CPU]        
Task Name    : [4]                 [SSD]
 Continue to : [GPU]               
 Redirect to : [Remove SSD]        
Task Name    : [Repair]            [1]
Task Name    : [Approve]           [1]

Done!
Press Enter Key to Exit ... 
gsingh520@matrix:~/oop345/ms1> exit
exit

Script done on Wed 21 Mar 2018 01:53:40 AM EDT
