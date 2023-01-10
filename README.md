# ticTacToeInCPP_task1

### Other contributors only did a small bug fix, doing this resulted in extra points for them. Besides these small bug fixes everything else was done by me.

I played a lot with GitHub actions and automation. This wasn't for points, I already passed this course so did what I like.

## How to run?

If you have a Windows machine, download the builded artifact. More info under windows.

For anything else, I advise running docker, but you can also compile from scratch if this is your preferred method.

### Docker

Pull the docker container from the packages tab, currently support it on linux/amd64,linux/arm64 and linux/arm/v7. This should work on almost all machines, but if it doesnt you can make a issue for whatever architecture you need. Or even better, fix it yourself and submit a pull request. After pulling it, simply run the image.

You must run with the -it flag.

For example: ```sudo docker run -it <image id>```

Showcase on the pynq z2 -> https://www.youtube.com/watch?v=4sYgRcMa_cc

### Windows

For windows, you can download the builded artifact (which can be found in any of the latest actions), unzip and run the EXE. (DLL's **need** to be in the same folder as the executable).

### Anything else

If docker isn't an option, compile from scratch.
