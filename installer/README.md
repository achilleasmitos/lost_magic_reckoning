# Installer

The 'installer.sh' inside this directory takes care of the bundling (zipping) process of a Release version of our application. Right now, it looks for a Release build of the main executable inside the 'build/' folder, creates a new Release with the exe in it, then copies the 'resources/' folder alongside it. Finally, the installer zips (via `tar`) this Release folder and everything inside it into one file that is ready to be uploaded as a release of our application on GitHub.

Each step in the process is accompanied by an appropriate error handling with different exit codes and messages that inform the developer about what went wrong and what can possibly be done to fix it.

The important thing to remember is to have an up-to-date version of the Release build in the 'build/' directory, and not interfere with it or any previous Release folder that has remained there during the runtime of the installer.

# Release process

When the time has come for a new release, there are certain steps we need to follow, in order for the release to be as successful as possible. Here they are in order of execution:
1. **Create a release branch** from the latest master. The release branch should have the name `Release_vX_Y_Z`, where X.Y.Z is the version of the release (eg 1.0.6). This is the branch which will be heavily tested before release, with any emerging bugs being fixed for it first-hand. When all bugs have been fixed and the release is ready, continue with step 2.
The release branch remains in a 'no-op' condition after the release, for ever in our project.
2. **Update the 'CHANGELOGS.md'** inside the root folder with the latest changes. This file will outline (in bulletpoints) what changes were made in each publicly released version of the product. Keep this concise, and stick to the points that are **of interest to an end user**!
3. **Update the main 'README.md'** if necessary.
4. **Update the 'Build Release' task** in '.vscode/tasks.json'. Specifically, copy-paste the files-to-be-built from the Debug Build task to this one, and make any other necessary changes.
5. **Open a pull-request** with the changes from steps 2-4 to master. When that is approved and merged, cherry-pick those changes to the release branch from step 1.
6. **Freeze the release branch** once the cherry-pick from the previous step has been merged to it.
7. **Run the 'Build Release' task** and wait for its successful completion.
8. **Run the 'installer/installer.sh' script** and wait for its successful completion. Speak to the admins if something went wrong with steps 7 and 8.
9. **Upload the zipped file** produced by the installer to GitHub and **finalize the release**!
10. _Drink a cup of coffee_ and enjoy the fruits of your labor.
