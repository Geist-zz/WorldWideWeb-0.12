                                                                         Read Me

                         WORLDWIDEWEB DISTRIBUTED CODE

   See also the CERN copyright[1] . This directory ("hypertext") contains
   information about hypertext, hypertext systems, and the WorldWideWeb
   project. If you have taken this with a .tar file, you will have only a
   subset of the files. 
DOCUMENTATION
   This directory and its sub-directories contain example hypertext. The text
   is an extract of the text from the WorldWideWeb (WWW) project documentation.
   
   The text is provided as example hypertext only, not for general
   distribution. The accuracy of any information is not guaranteed, and no
   responsibility will be accepted by the authors for any loss or damage due to
   inaccuracy or omission.
   
   The information about the WWW project is internal project documentation
   provided only to certain collaborators. It should not be copied or
   distributed to others without the authority of the WWW team.
   
   This is a snapshot of a changing hypertext system. It is inevitably out of
   date, and may be inconsistent.  There are links to information which is not
   provided here.  If any of these facts cause a problem, you should access the
   original master data over the network, or mail us. Currently (Mar 91)
   network access requires you to be able to NFS mount our files, which may
   only be done from specific nodes with permission. In the future we shall
   make this information available via  anonymous FTP or HTTP from the
   browsers. 
CODE
   The browser for the NeXT is those files contained in the application
   directory WWW/Next/Implementation/WorldWideWeb.app and is compiled.
   
   The line Mode browser is in WWW/LineMode/Implementation/... (See
   Installation notes[2])
   
   Subdirectories to that directory contain Makefiles for systems to which we
   have already ported.  If your system is not among them, make a new
   subdirectory with the system name, and copy the Makefile from an existing
   one. Change the directory names as needed. PLEASE INFORM US OF THE CHANGES
   WHEN YOU HAVE DONE THE PORT. This is a condidtion of  your use of this code,
   and will save others repeating your work, and save you repeating it in
   future releases.
   
   Whe you install the browsers,  remember to configure the default page. This
   is /usr/local/lib/WWW/default.html for the line mode browser, and
   .../WorldWideWeb.app/default.html for the NeXT browser. These must point to
   some useful information!  You should keep them up to date with pointers to
   info on your site and elsewhere.
   
   Most of the documentation is in hypertext, and so wil be readable most
   easily with a browser...
   
   Your comments will of course be most appreciated. If you write your own
   hypertext and make it available by anonymous ftp, tell us and we'll put some
   pointers to it in ours. This way, the web spreads... 
                                                                 Tim Berners-Lee
                                                                                
                                                            WorldWideWeb project
                                                                                
                                               CERN, 1211 Geneva 23, Switzerland
                                                                                
         Tel: +41 22 767 3755; Fax: +41 22 767 7155; email: tbl@cernvax.cern.ch 
