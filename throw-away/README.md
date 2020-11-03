# Throw away code
throw away code for the visual localization project.
## RTSP
A simple real-time streaming protocal making optimal use of the NVIDA hardware with gstreamer.
### Dependecies:
```
sudo apt-get install libgstrtspserver-1.0 libgsreamer1.0-dev
```
For the bassler camera you need the gstreamer plug-ins for bassler
```
git clone https://github.com/zingmars/gst-pylonsrc.git
```
I had to change the names in some of my directories. lib=lib64 and pylon=pylon4.
### Getting started
```
make rtsp-server
./rtsp-server "nvarguscamerasrc device=\dev\video0 ! omxh265enc ! rtph265pay name=pay0 pt=96"
```
Or with the bassler camera you can start with:
```
./rtsp-server "pylonsrc imageformat=mono8 autoexposure=continuous autogain=continuous ! videoconvert ! omxh265enc ! rtph265pay name=pay0 pt=96"
```
To connect you can use for example:
```
gst-launch-1.0 rtspsrc location='$RTSP_PATH' latency=200 ! rtph265depay ! h265parse ! omxh265dec ! nveglglessink
```
### Store camera stream
an example filesink of an mkv file is:
```
gst-launch-1.0 pylonsrc imageformat=mono8 autoexposure=continuous autogain=continuous ! videoconvert ! matroskamux ! filesink location=test.mkv
```
You can preview the stored video with
```
gst-launch-1.0 tcpclientsrc host=192.168.178.191 port=5000 ! tsdemux ! h265parse ! omxh265dec ! videoconvert ! nveglglessink sync=false -e
```