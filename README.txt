Entity Construction Template
-----------------------------


Choose the 3 different names for your custom entity

MACHINE
  eg.  my_module
  Generall stick to lowercase letters and underscores, start with a letter.

OOP 
  eg.  MyModule
  This is for the class names. Capitalize first letter of each word,
  acronyms are capitalized also, eg UI for user interface.
  
HUMAN
  eg.  My Module
  This will show up on UI's and other places, can have spaces.
  
Rename the .info, .install, .module, admin.inc files to your machine name.
eg. customentity.info = my_module.info

Search within the: .info, .install, .module, .admin.inc for the tokens listed
below and replace them with the corresponding name you have chosen.
  
customentity_m = The MACHINE name of the entity 
  
customentity_o = The OOP machine name of the entity  
  
customentity_h = The HUMAN readable name of the entity
  