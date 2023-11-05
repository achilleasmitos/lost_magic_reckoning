Inside the 'src/resources/images' folder sits the 'application_icon.ico' file, which is the icon used for our application. In the 'src/application_info' folder sits another file called 'application_icon.rc'. This file is pre-processed once with `windres` for Windows, using the following command:
```
windres application_icon.rc -O coff -o application_icon.res
```
(`windres` should be part of the MingW suite in git-bash; the command above is run in git-bash when the cwd is 'src/application_info')
The resulting `coff` file 'application_icon.res' is then linked into our executable using the standard build procedure of g++, simply by including it into the list of other `.cpp` files.
All files mentioned above should be checked-in, so that the `windres` command above does not need to be run with each build. If one wants to change the icon, then all they have to do is replace the `.ico` file above, run the `windres` command as described above, verify successful modification by building the application once, then commit their (three) modifed files.

An entirely similar procedure is followed for the 'application_info.rc' file which provides the built executable with the necessary info (file version, company name, legal rights and so on). This file is usually changed before any new release.
