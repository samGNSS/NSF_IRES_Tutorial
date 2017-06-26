#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Audio streaming simulation
# Author: Sam Schmidt
# Description: PCM encode the output of your soundcard and transmit with PSK modulation
# Generated: Tue Jun 13 05:31:48 2017
##################################################

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"

from PyQt4 import Qt
from gnuradio import audio
from gnuradio import blocks
from gnuradio import channels
from gnuradio import digital
from gnuradio import eng_notation
from gnuradio import filter
from gnuradio import gr
from gnuradio import qtgui
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from gnuradio.qtgui import Range, RangeWidget
from optparse import OptionParser
import sip
import sys
from gnuradio import qtgui


class top_block(gr.top_block, Qt.QWidget):

    def __init__(self):
        gr.top_block.__init__(self, "Audio streaming simulation")
        Qt.QWidget.__init__(self)
        self.setWindowTitle("Audio streaming simulation")
        qtgui.util.check_set_qss()
        try:
            self.setWindowIcon(Qt.QIcon.fromTheme('gnuradio-grc'))
        except:
            pass
        self.top_scroll_layout = Qt.QVBoxLayout()
        self.setLayout(self.top_scroll_layout)
        self.top_scroll = Qt.QScrollArea()
        self.top_scroll.setFrameStyle(Qt.QFrame.NoFrame)
        self.top_scroll_layout.addWidget(self.top_scroll)
        self.top_scroll.setWidgetResizable(True)
        self.top_widget = Qt.QWidget()
        self.top_scroll.setWidget(self.top_widget)
        self.top_layout = Qt.QVBoxLayout(self.top_widget)
        self.top_grid_layout = Qt.QGridLayout()
        self.top_layout.addLayout(self.top_grid_layout)

        self.settings = Qt.QSettings("GNU Radio", "top_block")
        self.restoreGeometry(self.settings.value("geometry").toByteArray())

        ##################################################
        # Variables
        ##################################################
        self.tx_filter_taps = tx_filter_taps = [0.0015483106253668666, 0.003957886714488268, -0.0020489732269197702, -0.0047193532809615135, 0.003015669994056225, 0.006161840632557869, -0.004648027941584587, -0.008288915269076824, 0.007166899275034666, 0.011077441275119781, -0.010816098190844059, -0.014477620832622051, 0.01586749032139778, 0.01841413415968418, -0.02263171412050724, -0.022788356989622116, 0.031478412449359894, 0.027481593191623688, -0.04287286475300789, -0.03235916793346405, 0.05744221433997154, 0.037275269627571106, -0.07609836012125015, -0.042078305035829544, 0.10027746856212616, 0.046616580337285995, -0.13244350254535675, -0.05074409395456314, 0.17726430296897888, 0.05432608723640442, -0.24480342864990234, -0.05724430829286575, 0.36136820912361145, 0.059401605278253555, -0.6237380504608154, -0.06072569638490677, 1.904083490371704, 3.0586037635803223, 1.904083490371704, -0.06072569638490677, -0.6237380504608154, 0.059401605278253555, 0.36136820912361145, -0.05724430829286575, -0.24480342864990234, 0.05432608723640442, 0.17726430296897888, -0.05074409395456314, -0.13244350254535675, 0.046616580337285995, 0.10027746856212616, -0.042078305035829544, -0.07609836012125015, 0.037275269627571106, 0.05744221433997154, -0.03235916793346405, -0.04287286475300789, 0.027481593191623688, 0.031478412449359894, -0.022788356989622116, -0.02263171412050724, 0.01841413415968418, 0.01586749032139778, -0.014477620832622051, -0.010816098190844059, 0.011077441275119781, 0.007166899275034666, -0.008288915269076824, -0.004648027941584587, 0.006161840632557869, 0.003015669994056225, -0.0047193532809615135, -0.0020489732269197702, 0.003957886714488268, 0.0015483106253668666]
        self.rx_filter_taps = rx_filter_taps = filter.firdes.low_pass_2(1,44100*2,10000,2000,100)
        self.noiseVolt = noiseVolt = 0.001
        self.freqOff = freqOff = 0

        ##################################################
        # Blocks
        ##################################################
        self._noiseVolt_range = Range(0, 10, .0001, 0.001, 200)
        self._noiseVolt_win = RangeWidget(self._noiseVolt_range, self.set_noiseVolt, 'Noise Voltage', "counter_slider", float)
        self.top_layout.addWidget(self._noiseVolt_win)
        self._freqOff_range = Range(0, 1, 0.0001, 0, 200)
        self._freqOff_win = RangeWidget(self._freqOff_range, self.set_freqOff, 'Frequency Offset ', "counter_slider", float)
        self.top_layout.addWidget(self._freqOff_win)
        self.all_the_tabs = Qt.QTabWidget()
        self.all_the_tabs_widget_0 = Qt.QWidget()
        self.all_the_tabs_layout_0 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.all_the_tabs_widget_0)
        self.all_the_tabs_grid_layout_0 = Qt.QGridLayout()
        self.all_the_tabs_layout_0.addLayout(self.all_the_tabs_grid_layout_0)
        self.all_the_tabs.addTab(self.all_the_tabs_widget_0, 'Tx')
        self.all_the_tabs_widget_1 = Qt.QWidget()
        self.all_the_tabs_layout_1 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.all_the_tabs_widget_1)
        self.all_the_tabs_grid_layout_1 = Qt.QGridLayout()
        self.all_the_tabs_layout_1.addLayout(self.all_the_tabs_grid_layout_1)
        self.all_the_tabs.addTab(self.all_the_tabs_widget_1, 'Channel')
        self.all_the_tabs_widget_2 = Qt.QWidget()
        self.all_the_tabs_layout_2 = Qt.QBoxLayout(Qt.QBoxLayout.TopToBottom, self.all_the_tabs_widget_2)
        self.all_the_tabs_grid_layout_2 = Qt.QGridLayout()
        self.all_the_tabs_layout_2.addLayout(self.all_the_tabs_grid_layout_2)
        self.all_the_tabs.addTab(self.all_the_tabs_widget_2, 'Rx')
        self.top_layout.addWidget(self.all_the_tabs)
        self.qtgui_time_sink_x_0_0_0_0 = qtgui.time_sink_f(
        	2048, #size
        	44100*2, #samp_rate
        	"Scaled Time Domian Input after Interpolation", #name
        	2 #number of inputs
        )
        self.qtgui_time_sink_x_0_0_0_0.set_update_time(0.10)
        self.qtgui_time_sink_x_0_0_0_0.set_y_axis(-1, 255)
        
        self.qtgui_time_sink_x_0_0_0_0.set_y_label('Amplitude', "")
        
        self.qtgui_time_sink_x_0_0_0_0.enable_tags(-1, False)
        self.qtgui_time_sink_x_0_0_0_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, qtgui.TRIG_SLOPE_POS, 0.0, 0, 0, "")
        self.qtgui_time_sink_x_0_0_0_0.enable_autoscale(False)
        self.qtgui_time_sink_x_0_0_0_0.enable_grid(True)
        self.qtgui_time_sink_x_0_0_0_0.enable_axis_labels(True)
        self.qtgui_time_sink_x_0_0_0_0.enable_control_panel(False)
        
        if not True:
          self.qtgui_time_sink_x_0_0_0_0.disable_legend()
        
        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
                  "magenta", "yellow", "dark red", "dark green", "blue"]
        styles = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        markers = [-1, -1, -1, -1, -1,
                   -1, -1, -1, -1, -1]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]
        
        for i in xrange(2):
            if len(labels[i]) == 0:
                self.qtgui_time_sink_x_0_0_0_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_time_sink_x_0_0_0_0.set_line_label(i, labels[i])
            self.qtgui_time_sink_x_0_0_0_0.set_line_width(i, widths[i])
            self.qtgui_time_sink_x_0_0_0_0.set_line_color(i, colors[i])
            self.qtgui_time_sink_x_0_0_0_0.set_line_style(i, styles[i])
            self.qtgui_time_sink_x_0_0_0_0.set_line_marker(i, markers[i])
            self.qtgui_time_sink_x_0_0_0_0.set_line_alpha(i, alphas[i])
        
        self._qtgui_time_sink_x_0_0_0_0_win = sip.wrapinstance(self.qtgui_time_sink_x_0_0_0_0.pyqwidget(), Qt.QWidget)
        self.all_the_tabs_layout_0.addWidget(self._qtgui_time_sink_x_0_0_0_0_win)
        self.qtgui_time_sink_x_0_0 = qtgui.time_sink_f(
        	2048, #size
        	44100, #samp_rate
        	"Received Signal Spectrum", #name
        	2 #number of inputs
        )
        self.qtgui_time_sink_x_0_0.set_update_time(0.10)
        self.qtgui_time_sink_x_0_0.set_y_axis(-2, 2)
        
        self.qtgui_time_sink_x_0_0.set_y_label('Amplitude', "")
        
        self.qtgui_time_sink_x_0_0.enable_tags(-1, False)
        self.qtgui_time_sink_x_0_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, qtgui.TRIG_SLOPE_POS, 0.0, 0, 0, "")
        self.qtgui_time_sink_x_0_0.enable_autoscale(False)
        self.qtgui_time_sink_x_0_0.enable_grid(True)
        self.qtgui_time_sink_x_0_0.enable_axis_labels(True)
        self.qtgui_time_sink_x_0_0.enable_control_panel(False)
        
        if not True:
          self.qtgui_time_sink_x_0_0.disable_legend()
        
        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
                  "magenta", "yellow", "dark red", "dark green", "blue"]
        styles = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        markers = [-1, -1, -1, -1, -1,
                   -1, -1, -1, -1, -1]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]
        
        for i in xrange(2):
            if len(labels[i]) == 0:
                self.qtgui_time_sink_x_0_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_time_sink_x_0_0.set_line_label(i, labels[i])
            self.qtgui_time_sink_x_0_0.set_line_width(i, widths[i])
            self.qtgui_time_sink_x_0_0.set_line_color(i, colors[i])
            self.qtgui_time_sink_x_0_0.set_line_style(i, styles[i])
            self.qtgui_time_sink_x_0_0.set_line_marker(i, markers[i])
            self.qtgui_time_sink_x_0_0.set_line_alpha(i, alphas[i])
        
        self._qtgui_time_sink_x_0_0_win = sip.wrapinstance(self.qtgui_time_sink_x_0_0.pyqwidget(), Qt.QWidget)
        self.all_the_tabs_layout_2.addWidget(self._qtgui_time_sink_x_0_0_win)
        self.qtgui_freq_sink_x_1 = qtgui.freq_sink_c(
        	1024, #size
        	firdes.WIN_BLACKMAN_hARRIS, #wintype
        	0, #fc
        	44100*2, #bw
        	"Channel Spectrum", #name
        	1 #number of inputs
        )
        self.qtgui_freq_sink_x_1.set_update_time(0.10)
        self.qtgui_freq_sink_x_1.set_y_axis(-140, 10)
        self.qtgui_freq_sink_x_1.set_y_label('Relative Gain', 'dB')
        self.qtgui_freq_sink_x_1.set_trigger_mode(qtgui.TRIG_MODE_FREE, 0.0, 0, "")
        self.qtgui_freq_sink_x_1.enable_autoscale(False)
        self.qtgui_freq_sink_x_1.enable_grid(True)
        self.qtgui_freq_sink_x_1.set_fft_average(1.0)
        self.qtgui_freq_sink_x_1.enable_axis_labels(True)
        self.qtgui_freq_sink_x_1.enable_control_panel(False)
        
        if not True:
          self.qtgui_freq_sink_x_1.disable_legend()
        
        if "complex" == "float" or "complex" == "msg_float":
          self.qtgui_freq_sink_x_1.set_plot_pos_half(not True)
        
        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
                  "magenta", "yellow", "dark red", "dark green", "dark blue"]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]
        for i in xrange(1):
            if len(labels[i]) == 0:
                self.qtgui_freq_sink_x_1.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_freq_sink_x_1.set_line_label(i, labels[i])
            self.qtgui_freq_sink_x_1.set_line_width(i, widths[i])
            self.qtgui_freq_sink_x_1.set_line_color(i, colors[i])
            self.qtgui_freq_sink_x_1.set_line_alpha(i, alphas[i])
        
        self._qtgui_freq_sink_x_1_win = sip.wrapinstance(self.qtgui_freq_sink_x_1.pyqwidget(), Qt.QWidget)
        self.all_the_tabs_layout_1.addWidget(self._qtgui_freq_sink_x_1_win)
        self.qtgui_freq_sink_x_0_0 = qtgui.freq_sink_f(
        	1024, #size
        	firdes.WIN_BLACKMAN_hARRIS, #wintype
        	0, #fc
        	44100, #bw
        	"Input Spectrum before Scaling after Interpolation", #name
        	2 #number of inputs
        )
        self.qtgui_freq_sink_x_0_0.set_update_time(0.10)
        self.qtgui_freq_sink_x_0_0.set_y_axis(-140, 10)
        self.qtgui_freq_sink_x_0_0.set_y_label('Relative Gain', 'dB')
        self.qtgui_freq_sink_x_0_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, 0.0, 0, "")
        self.qtgui_freq_sink_x_0_0.enable_autoscale(False)
        self.qtgui_freq_sink_x_0_0.enable_grid(False)
        self.qtgui_freq_sink_x_0_0.set_fft_average(1.0)
        self.qtgui_freq_sink_x_0_0.enable_axis_labels(True)
        self.qtgui_freq_sink_x_0_0.enable_control_panel(False)
        
        if not True:
          self.qtgui_freq_sink_x_0_0.disable_legend()
        
        if "float" == "float" or "float" == "msg_float":
          self.qtgui_freq_sink_x_0_0.set_plot_pos_half(not True)
        
        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
                  "magenta", "yellow", "dark red", "dark green", "dark blue"]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]
        for i in xrange(2):
            if len(labels[i]) == 0:
                self.qtgui_freq_sink_x_0_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_freq_sink_x_0_0.set_line_label(i, labels[i])
            self.qtgui_freq_sink_x_0_0.set_line_width(i, widths[i])
            self.qtgui_freq_sink_x_0_0.set_line_color(i, colors[i])
            self.qtgui_freq_sink_x_0_0.set_line_alpha(i, alphas[i])
        
        self._qtgui_freq_sink_x_0_0_win = sip.wrapinstance(self.qtgui_freq_sink_x_0_0.pyqwidget(), Qt.QWidget)
        self.all_the_tabs_layout_0.addWidget(self._qtgui_freq_sink_x_0_0_win)
        self.qtgui_freq_sink_x_0 = qtgui.freq_sink_f(
        	1024, #size
        	firdes.WIN_BLACKMAN_hARRIS, #wintype
        	0, #fc
        	44100, #bw
        	"Received Time Domain Signal", #name
        	2 #number of inputs
        )
        self.qtgui_freq_sink_x_0.set_update_time(0.10)
        self.qtgui_freq_sink_x_0.set_y_axis(-140, 10)
        self.qtgui_freq_sink_x_0.set_y_label('Relative Gain', 'dB')
        self.qtgui_freq_sink_x_0.set_trigger_mode(qtgui.TRIG_MODE_FREE, 0.0, 0, "")
        self.qtgui_freq_sink_x_0.enable_autoscale(False)
        self.qtgui_freq_sink_x_0.enable_grid(False)
        self.qtgui_freq_sink_x_0.set_fft_average(1.0)
        self.qtgui_freq_sink_x_0.enable_axis_labels(True)
        self.qtgui_freq_sink_x_0.enable_control_panel(False)
        
        if not True:
          self.qtgui_freq_sink_x_0.disable_legend()
        
        if "float" == "float" or "float" == "msg_float":
          self.qtgui_freq_sink_x_0.set_plot_pos_half(not True)
        
        labels = ['', '', '', '', '',
                  '', '', '', '', '']
        widths = [1, 1, 1, 1, 1,
                  1, 1, 1, 1, 1]
        colors = ["blue", "red", "green", "black", "cyan",
                  "magenta", "yellow", "dark red", "dark green", "dark blue"]
        alphas = [1.0, 1.0, 1.0, 1.0, 1.0,
                  1.0, 1.0, 1.0, 1.0, 1.0]
        for i in xrange(2):
            if len(labels[i]) == 0:
                self.qtgui_freq_sink_x_0.set_line_label(i, "Data {0}".format(i))
            else:
                self.qtgui_freq_sink_x_0.set_line_label(i, labels[i])
            self.qtgui_freq_sink_x_0.set_line_width(i, widths[i])
            self.qtgui_freq_sink_x_0.set_line_color(i, colors[i])
            self.qtgui_freq_sink_x_0.set_line_alpha(i, alphas[i])
        
        self._qtgui_freq_sink_x_0_win = sip.wrapinstance(self.qtgui_freq_sink_x_0.pyqwidget(), Qt.QWidget)
        self.all_the_tabs_layout_2.addWidget(self._qtgui_freq_sink_x_0_win)
        self.interp_fir_filter_xxx_0_0 = filter.interp_fir_filter_fff(2, (tx_filter_taps))
        self.interp_fir_filter_xxx_0_0.declare_sample_delay(0)
        self.interp_fir_filter_xxx_0 = filter.interp_fir_filter_fff(2, (tx_filter_taps))
        self.interp_fir_filter_xxx_0.declare_sample_delay(0)
        self.fir_filter_xxx_0_0 = filter.fir_filter_fff(2, (rx_filter_taps))
        self.fir_filter_xxx_0_0.declare_sample_delay(0)
        self.fir_filter_xxx_0 = filter.fir_filter_fff(2, (rx_filter_taps))
        self.fir_filter_xxx_0.declare_sample_delay(0)
        self.digital_dxpsk_mod_0_0 = digital.dqpsk_mod(
        	samples_per_symbol=2,
        	excess_bw=0.35,
        	mod_code="gray",
        	verbose=False,
        	log=False)
        	
        self.digital_dxpsk_demod_0 = digital.dqpsk_demod(
        	samples_per_symbol=2,
        	excess_bw=0.35,
        	freq_bw=6.28/100.0,
        	phase_bw=6.28/100.0,
        	timing_bw=6.28/100.0,
        	mod_code="gray",
        	verbose=False,
        	log=False
        )
        self.channels_channel_model_0 = channels.channel_model(
        	noise_voltage=noiseVolt,
        	frequency_offset=freqOff,
        	epsilon=1.0,
        	taps=(1.0 + 1.0j, ),
        	noise_seed=0,
        	block_tags=False
        )
        self.blocks_wavfile_sink_0 = blocks.wavfile_sink('/home/harrison/Desktop/simulation_test.wav', 2, 44100, 8)
        self.blocks_uchar_to_float_0_1 = blocks.uchar_to_float()
        self.blocks_uchar_to_float_0_0_0 = blocks.uchar_to_float()
        self.blocks_pack_k_bits_bb_0 = blocks.pack_k_bits_bb(8)
        self.blocks_multiply_const_vxx_0_1_0 = blocks.multiply_const_vff((1/127., ))
        self.blocks_multiply_const_vxx_0_1 = blocks.multiply_const_vff((1/127., ))
        self.blocks_multiply_const_vxx_0_0 = blocks.multiply_const_vff((127, ))
        self.blocks_multiply_const_vxx_0 = blocks.multiply_const_vff((127, ))
        self.blocks_interleave_0 = blocks.interleave(gr.sizeof_char*1, 1)
        self.blocks_float_to_uchar_0_0 = blocks.float_to_uchar()
        self.blocks_float_to_uchar_0 = blocks.float_to_uchar()
        self.blocks_deinterleave_0_0 = blocks.deinterleave(gr.sizeof_char*1, 1)
        self.blocks_add_const_vxx_0_1_0 = blocks.add_const_vff((-1, ))
        self.blocks_add_const_vxx_0_1 = blocks.add_const_vff((-1, ))
        self.blocks_add_const_vxx_0_0 = blocks.add_const_vff((1, ))
        self.blocks_add_const_vxx_0 = blocks.add_const_vff((1, ))
        self.audio_source_0 = audio.source(44100, 'pulse_monitor', True)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.audio_source_0, 0), (self.interp_fir_filter_xxx_0, 0))    
        self.connect((self.audio_source_0, 1), (self.interp_fir_filter_xxx_0_0, 0))    
        self.connect((self.blocks_add_const_vxx_0, 0), (self.blocks_multiply_const_vxx_0, 0))    
        self.connect((self.blocks_add_const_vxx_0_0, 0), (self.blocks_multiply_const_vxx_0_0, 0))    
        self.connect((self.blocks_add_const_vxx_0_1, 0), (self.fir_filter_xxx_0, 0))    
        self.connect((self.blocks_add_const_vxx_0_1_0, 0), (self.fir_filter_xxx_0_0, 0))    
        self.connect((self.blocks_deinterleave_0_0, 1), (self.blocks_uchar_to_float_0_0_0, 0))    
        self.connect((self.blocks_deinterleave_0_0, 0), (self.blocks_uchar_to_float_0_1, 0))    
        self.connect((self.blocks_float_to_uchar_0, 0), (self.blocks_interleave_0, 0))    
        self.connect((self.blocks_float_to_uchar_0_0, 0), (self.blocks_interleave_0, 1))    
        self.connect((self.blocks_interleave_0, 0), (self.digital_dxpsk_mod_0_0, 0))    
        self.connect((self.blocks_multiply_const_vxx_0, 0), (self.blocks_float_to_uchar_0, 0))    
        self.connect((self.blocks_multiply_const_vxx_0, 0), (self.qtgui_time_sink_x_0_0_0_0, 0))    
        self.connect((self.blocks_multiply_const_vxx_0_0, 0), (self.blocks_float_to_uchar_0_0, 0))    
        self.connect((self.blocks_multiply_const_vxx_0_0, 0), (self.qtgui_time_sink_x_0_0_0_0, 1))    
        self.connect((self.blocks_multiply_const_vxx_0_1, 0), (self.blocks_add_const_vxx_0_1, 0))    
        self.connect((self.blocks_multiply_const_vxx_0_1_0, 0), (self.blocks_add_const_vxx_0_1_0, 0))    
        self.connect((self.blocks_pack_k_bits_bb_0, 0), (self.blocks_deinterleave_0_0, 0))    
        self.connect((self.blocks_uchar_to_float_0_0_0, 0), (self.blocks_multiply_const_vxx_0_1_0, 0))    
        self.connect((self.blocks_uchar_to_float_0_1, 0), (self.blocks_multiply_const_vxx_0_1, 0))    
        self.connect((self.channels_channel_model_0, 0), (self.digital_dxpsk_demod_0, 0))    
        self.connect((self.channels_channel_model_0, 0), (self.qtgui_freq_sink_x_1, 0))    
        self.connect((self.digital_dxpsk_demod_0, 0), (self.blocks_pack_k_bits_bb_0, 0))    
        self.connect((self.digital_dxpsk_mod_0_0, 0), (self.channels_channel_model_0, 0))    
        self.connect((self.fir_filter_xxx_0, 0), (self.blocks_wavfile_sink_0, 0))    
        self.connect((self.fir_filter_xxx_0, 0), (self.qtgui_freq_sink_x_0, 0))    
        self.connect((self.fir_filter_xxx_0, 0), (self.qtgui_time_sink_x_0_0, 0))    
        self.connect((self.fir_filter_xxx_0_0, 0), (self.blocks_wavfile_sink_0, 1))    
        self.connect((self.fir_filter_xxx_0_0, 0), (self.qtgui_freq_sink_x_0, 1))    
        self.connect((self.fir_filter_xxx_0_0, 0), (self.qtgui_time_sink_x_0_0, 1))    
        self.connect((self.interp_fir_filter_xxx_0, 0), (self.blocks_add_const_vxx_0, 0))    
        self.connect((self.interp_fir_filter_xxx_0, 0), (self.qtgui_freq_sink_x_0_0, 0))    
        self.connect((self.interp_fir_filter_xxx_0_0, 0), (self.blocks_add_const_vxx_0_0, 0))    
        self.connect((self.interp_fir_filter_xxx_0_0, 0), (self.qtgui_freq_sink_x_0_0, 1))    

    def closeEvent(self, event):
        self.settings = Qt.QSettings("GNU Radio", "top_block")
        self.settings.setValue("geometry", self.saveGeometry())
        event.accept()

    def get_tx_filter_taps(self):
        return self.tx_filter_taps

    def set_tx_filter_taps(self, tx_filter_taps):
        self.tx_filter_taps = tx_filter_taps
        self.interp_fir_filter_xxx_0_0.set_taps((self.tx_filter_taps))
        self.interp_fir_filter_xxx_0.set_taps((self.tx_filter_taps))

    def get_rx_filter_taps(self):
        return self.rx_filter_taps

    def set_rx_filter_taps(self, rx_filter_taps):
        self.rx_filter_taps = rx_filter_taps
        self.fir_filter_xxx_0_0.set_taps((self.rx_filter_taps))
        self.fir_filter_xxx_0.set_taps((self.rx_filter_taps))

    def get_noiseVolt(self):
        return self.noiseVolt

    def set_noiseVolt(self, noiseVolt):
        self.noiseVolt = noiseVolt
        self.channels_channel_model_0.set_noise_voltage(self.noiseVolt)

    def get_freqOff(self):
        return self.freqOff

    def set_freqOff(self, freqOff):
        self.freqOff = freqOff
        self.channels_channel_model_0.set_frequency_offset(self.freqOff)


def main(top_block_cls=top_block, options=None):

    from distutils.version import StrictVersion
    if StrictVersion(Qt.qVersion()) >= StrictVersion("4.5.0"):
        style = gr.prefs().get_string('qtgui', 'style', 'raster')
        Qt.QApplication.setGraphicsSystem(style)
    qapp = Qt.QApplication(sys.argv)

    tb = top_block_cls()
    tb.start()
    tb.show()

    def quitting():
        tb.stop()
        tb.wait()
    qapp.connect(qapp, Qt.SIGNAL("aboutToQuit()"), quitting)
    qapp.exec_()


if __name__ == '__main__':
    main()
