To get the audio examples to run correctly, I had to modify the following lines in the gnuradio/config.conf file:
[audio_alsa]
default_input_device = default
default_output_device = default
nperiods = 4
period_time = 0.10 #default is 0.01
verbose = false


To make things easy, I decided to put my configs on github.

To use this folder, put it in /home/user and rename it ".gnuradio" make sure to back up your existing configs.

