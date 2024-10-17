  Instructions for installing/uninstalling the software tag file for lmadmin
  --------------------------------------------------------------------------

When lmadmin is *not* installed on removable media (like a USB drive):

After the installation of lmadmin, the software tag file (of the form 
"regid.2009-06.com.flexerasoftware_<UNIQUE_ID>.swidtag"), which gets installed 
in the lmadmin install-folder (OR the "lmadmin" folder in the FlexNet Publisher 
kit), has to be manually copied to the following location (based on the platform).

Apple Mac OS X Leopard:		<root>/Library/Application Support/<software creator regid>
Apple Mac OS X pre-Leopard:	Application Directory/<program.app package>/contents
(NOTE: software identification tags should be included in the application 
directory by default for all operating systems (see below). 
Pre-Leopard OS X systems should also use this location as the default location.)

UNIX flavours and Linux:	/usr/share/<software creator regid>

Windows NT:					C:\Winnt\All Users\Application Data\<software creator regid>

Windows 2000 Professional,
Windows Server 2000,
Windows Server 2003:		%AllUsersProfile%\Application Data\<software creator regid>

Microsoft Server 2008,
Windows 7 and later:					%Program Data%\<software creator regid>

where <software creator regid> stands for "regid.2009-06.com.flexerasoftware".

For example, "C:\Program Data\regid.2009-06.com.flexerasoftware\regid.2009-06.com.flexerasoftware_190fedfc-1f0a-11b2-9a53-9eddaa5ea056.swidtag".
Note that the regid appears twice in this path; once as a folder name and once as part of the tag file name.

You should also ensure that the tag file is uninstalled from this location when lmadmin is uninstalled.
