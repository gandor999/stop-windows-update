#### Auto disable windows update

This is an .exe file that reads the config.yaml file (where the content for this is the path to the softwaredistribution download dir that you can set) and uses the input as one of the commands to be executed with system() to delete the download dir.

It grew a bit tiresome to do it manually everytime I turned on the computer so instead I made this to automate that and to maybe brush up on my c++...

To run the app:

- compile the app: `g++ -o stop-windows-update stop-windows-update.cpp`
- make a `config.yaml` file with the contents being:
    ```
        softwareDistributionDownloadPath: C:\Windows\SoftwareDistribution\Download
    ```
    and place this along within the same dir as the .exe file
- run .exe as administrator
