# Readme file for Unihan repository
### Daniel J. Greenhoe
### https://github.com/dgreenhoe/unihan/


## CJK Unicode fonts

CJK Unicode fonts seek to encode the characters for 
traditional Chinese, simplified Chinese, Japanese, and Korean characters
into one font file (e.g. an .otf file).


## Traditional to simplified mapping

When typesetting Chinese characters, one may want to produce a document or
pair of documents that support both traditional and simplified characters.
However, ideally, one would like to just type the document once using 
one character type and then automatically map to the other type when necessary.
This repository supports the method of first using traditional characters
and then mapping, when necessary, to simplified characters.
A mapping is "necessary" when there is "variation" between the two for a 
given character.


## Chinese Variants 

The traditional-simplified variants are identified in a document from www.unicode.org
called "Unihan_Variants.txt". Version 10.0.0, for example, of this file can be found
in Unihan.zip in https://www.unicode.org/Public/10.0.0/ucd/.


## TECkit mapping for Chinese variants

A TECkit map is a Unicode mapping file which, after compiling, can be used with 
the XeLaTeX software to map one or more Unicode points to another Unicode point.
  scripts.sil.org/teckit
Note that before being used, a TECkit .map file must be compiled to a .tec file.


## C source for generating TECkit map

In this repository, the source var2map.c can be compiled to generate a TECkit map
from a variants .txt file like this:
  var2map.exe Unihan_Variants_10-0-0.txt zht2zhs_10-0-0.map


## TECkit maps in this repository
  * zht2zhs_06-1-0.map: mapping based on Unihan_Variants.txt version 06.1.0
  * zht2zhs_10-0-0.map: mapping based on Unihan_Variants.txt version 10.0.0

