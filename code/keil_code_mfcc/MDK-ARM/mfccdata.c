#include "mfccdata.h"


const float32_t mfcc_dct_coefs_config1_f32[NB_MFCC_DCT_COEFS_CONFIG1_F32]={
0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,
0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,
0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,
0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,
0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,
0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,0.176777f,
0.176777f,0.176777f,0.176777f,0.176777f,0.176723f,0.176298f,0.175447f,0.174174f,0.172481f,0.170373f,
0.167854f,0.164931f,0.161611f,0.157901f,0.153811f,0.149350f,0.144530f,0.139361f,0.133857f,0.128030f,
0.121895f,0.115466f,0.108759f,0.101789f,0.094575f,0.087133f,0.079481f,0.071637f,0.063621f,0.055452f,
0.047149f,0.038732f,0.030222f,0.021639f,0.013005f,0.004338f,-0.004338f,-0.013005f,-0.021639f,-0.030222f,
-0.038732f,-0.047149f,-0.055452f,-0.063621f,-0.071637f,-0.079481f,-0.087133f,-0.094575f,-0.101789f,-0.108759f,
-0.115466f,-0.121895f,-0.128030f,-0.133857f,-0.139361f,-0.144530f,-0.149350f,-0.153811f,-0.157901f,-0.161611f,
-0.164931f,-0.167854f,-0.170373f,-0.172481f,-0.174174f,-0.175447f,-0.176298f,-0.176723f,0.176564f,0.174863f,
0.171479f,0.166443f,0.159804f,0.151626f,0.141988f,0.130983f,0.118716f,0.105306f,0.090881f,0.075582f,
0.059554f,0.042953f,0.025939f,0.008674f,-0.008674f,-0.025939f,-0.042953f,-0.059554f,-0.075582f,-0.090881f,
-0.105306f,-0.118716f,-0.130983f,-0.141988f,-0.151626f,-0.159804f,-0.166443f,-0.171479f,-0.174863f,-0.176564f,
-0.176564f,-0.174863f,-0.171479f,-0.166443f,-0.159804f,-0.151626f,-0.141988f,-0.130983f,-0.118716f,-0.105306f,
-0.090881f,-0.075582f,-0.059554f,-0.042953f,-0.025939f,-0.008674f,0.008674f,0.025939f,0.042953f,0.059554f,
0.075582f,0.090881f,0.105306f,0.118716f,0.130983f,0.141988f,0.151626f,0.159804f,0.166443f,0.171479f,
0.174863f,0.176564f,0.176298f,0.172481f,0.164931f,0.153811f,0.139361f,0.121895f,0.101789f,0.079481f,
0.055452f,0.030222f,0.004338f,-0.021639f,-0.047149f,-0.071637f,-0.094575f,-0.115466f,-0.133857f,-0.149350f,
-0.161611f,-0.170373f,-0.175447f,-0.176723f,-0.174174f,-0.167854f,-0.157901f,-0.144530f,-0.128030f,-0.108759f,
-0.087133f,-0.063621f,-0.038732f,-0.013005f,0.013005f,0.038732f,0.063621f,0.087133f,0.108759f,0.128030f,
0.144530f,0.157901f,0.167854f,0.174174f,0.176723f,0.175447f,0.170373f,0.161611f,0.149350f,0.133857f,
0.115466f,0.094575f,0.071637f,0.047149f,0.021639f,-0.004338f,-0.030222f,-0.055452f,-0.079481f,-0.101789f,
-0.121895f,-0.139361f,-0.153811f,-0.164931f,-0.172481f,-0.176298f,0.175925f,0.169165f,0.155903f,0.136650f,
0.112146f,0.083332f,0.051316f,0.017327f,-0.017327f,-0.051316f,-0.083332f,-0.112146f,-0.136650f,-0.155903f,
-0.169165f,-0.175925f,-0.175925f,-0.169165f,-0.155903f,-0.136650f,-0.112146f,-0.083332f,-0.051316f,-0.017327f,
0.017327f,0.051316f,0.083332f,0.112146f,0.136650f,0.155903f,0.169165f,0.175925f,0.175925f,0.169165f,
0.155903f,0.136650f,0.112146f,0.083332f,0.051316f,0.017327f,-0.017327f,-0.051316f,-0.083332f,-0.112146f,
-0.136650f,-0.155903f,-0.169165f,-0.175925f,-0.175925f,-0.169165f,-0.155903f,-0.136650f,-0.112146f,-0.083332f,
-0.051316f,-0.017327f,0.017327f,0.051316f,0.083332f,0.112146f,0.136650f,0.155903f,0.169165f,0.175925f,
0.175447f,0.164931f,0.144530f,0.115466f,0.079481f,0.038732f,-0.004338f,-0.047149f,-0.087133f,-0.121895f,
-0.149350f,-0.167854f,-0.176298f,-0.174174f,-0.161611f,-0.139361f,-0.108759f,-0.071637f,-0.030222f,0.013005f,
0.055452f,0.094575f,0.128030f,0.153811f,0.170373f,0.176723f,0.172481f,0.157901f,0.133857f,0.101789f,
0.063621f,0.021639f,-0.021639f,-0.063621f,-0.101789f,-0.133857f,-0.157901f,-0.172481f,-0.176723f,-0.170373f,
-0.153811f,-0.128030f,-0.094575f,-0.055452f,-0.013005f,0.030222f,0.071637f,0.108759f,0.139361f,0.161611f,
0.174174f,0.176298f,0.167854f,0.149350f,0.121895f,0.087133f,0.047149f,0.004338f,-0.038732f,-0.079481f,
-0.115466f,-0.144530f,-0.164931f,-0.175447f,0.174863f,0.159804f,0.130983f,0.090881f,0.042953f,-0.008674f,
-0.059554f,-0.105306f,-0.141988f,-0.166443f,-0.176564f,-0.171479f,-0.151626f,-0.118716f,-0.075582f,-0.025939f,
0.025939f,0.075582f,0.118716f,0.151626f,0.171479f,0.176564f,0.166443f,0.141988f,0.105306f,0.059554f,
0.008674f,-0.042953f,-0.090881f,-0.130983f,-0.159804f,-0.174863f,-0.174863f,-0.159804f,-0.130983f,-0.090881f,
-0.042953f,0.008674f,0.059554f,0.105306f,0.141988f,0.166443f,0.176564f,0.171479f,0.151626f,0.118716f,
0.075582f,0.025939f,-0.025939f,-0.075582f,-0.118716f,-0.151626f,-0.171479f,-0.176564f,-0.166443f,-0.141988f,
-0.105306f,-0.059554f,-0.008674f,0.042953f,0.090881f,0.130983f,0.159804f,0.174863f,0.174174f,0.153811f,
0.115466f,0.063621f,0.004338f,-0.055452f,-0.108759f,-0.149350f,-0.172481f,-0.175447f,-0.157901f,-0.121895f,
-0.071637f,-0.013005f,0.047149f,0.101789f,0.144530f,0.170373f,0.176298f,0.161611f,0.128030f,0.079481f,
0.021639f,-0.038732f,-0.094575f,-0.139361f,-0.167854f,-0.176723f,-0.164931f,-0.133857f,-0.087133f,-0.030222f,
0.030222f,0.087133f,0.133857f,0.164931f,0.176723f,0.167854f,0.139361f,0.094575f,0.038732f,-0.021639f,
-0.079481f,-0.128030f,-0.161611f,-0.176298f,-0.170373f,-0.144530f,-0.101789f,-0.047149f,0.013005f,0.071637f,
0.121895f,0.157901f,0.175447f,0.172481f,0.149350f,0.108759f,0.055452f,-0.004338f,-0.063621f,-0.115466f,
-0.153811f,-0.174174f,0.173380f,0.146984f,0.098212f,0.034487f,-0.034487f,-0.098212f,-0.146984f,-0.173380f,
-0.173380f,-0.146984f,-0.098212f,-0.034487f,0.034487f,0.098212f,0.146984f,0.173380f,0.173380f,0.146984f,
0.098212f,0.034487f,-0.034487f,-0.098212f,-0.146984f,-0.173380f,-0.173380f,-0.146984f,-0.098212f,-0.034487f,
0.034487f,0.098212f,0.146984f,0.173380f,0.173380f,0.146984f,0.098212f,0.034487f,-0.034487f,-0.098212f,
-0.146984f,-0.173380f,-0.173380f,-0.146984f,-0.098212f,-0.034487f,0.034487f,0.098212f,0.146984f,0.173380f,
0.173380f,0.146984f,0.098212f,0.034487f,-0.034487f,-0.098212f,-0.146984f,-0.173380f,-0.173380f,-0.146984f,
-0.098212f,-0.034487f,0.034487f,0.098212f,0.146984f,0.173380f,0.172481f,0.139361f,0.079481f,0.004338f,
-0.071637f,-0.133857f,-0.170373f,-0.174174f,-0.144530f,-0.087133f,-0.013005f,0.063621f,0.128030f,0.167854f,
0.175447f,0.149350f,0.094575f,0.021639f,-0.055452f,-0.121895f,-0.164931f,-0.176298f,-0.153811f,-0.101789f,
-0.030222f,0.047149f,0.115466f,0.161611f,0.176723f,0.157901f,0.108759f,0.038732f,-0.038732f,-0.108759f,
-0.157901f,-0.176723f,-0.161611f,-0.115466f,-0.047149f,0.030222f,0.101789f,0.153811f,0.176298f,0.164931f,
0.121895f,0.055452f,-0.021639f,-0.094575f,-0.149350f,-0.175447f,-0.167854f,-0.128030f,-0.063621f,0.013005f,
0.087133f,0.144530f,0.174174f,0.170373f,0.133857f,0.071637f,-0.004338f,-0.079481f,-0.139361f,-0.172481f,
0.171479f,0.130983f,0.059554f,-0.025939f,-0.105306f,-0.159804f,-0.176564f,-0.151626f,-0.090881f,-0.008674f,
0.075582f,0.141988f,0.174863f,0.166443f,0.118716f,0.042953f,-0.042953f,-0.118716f,-0.166443f,-0.174863f,
-0.141988f,-0.075582f,0.008674f,0.090881f,0.151626f,0.176564f,0.159804f,0.105306f,0.025939f,-0.059554f,
-0.130983f,-0.171479f,-0.171479f,-0.130983f,-0.059554f,0.025939f,0.105306f,0.159804f,0.176564f,0.151626f,
0.090881f,0.008674f,-0.075582f,-0.141988f,-0.174863f,-0.166443f,-0.118716f,-0.042953f,0.042953f,0.118716f,
0.166443f,0.174863f,0.141988f,0.075582f,-0.008674f,-0.090881f,-0.151626f,-0.176564f,-0.159804f,-0.105306f,
-0.025939f,0.059554f,0.130983f,0.171479f,0.170373f,0.121895f,0.038732f,-0.055452f,-0.133857f,-0.174174f,
-0.164931f,-0.108759f,-0.021639f,0.071637f,0.144530f,0.176298f,0.157901f,0.094575f,0.004338f,-0.087133f,
-0.153811f,-0.176723f,-0.149350f,-0.079481f,0.013005f,0.101789f,0.161611f,0.175447f,0.139361f,0.063621f,
-0.030222f,-0.115466f,-0.167854f,-0.172481f,-0.128030f,-0.047149f,0.047149f,0.128030f,0.172481f,0.167854f,
0.115466f,0.030222f,-0.063621f,-0.139361f,-0.175447f,-0.161611f,-0.101789f,-0.013005f,0.079481f,0.149350f,
0.176723f,0.153811f,0.087133f,-0.004338f,-0.094575f,-0.157901f,-0.176298f,-0.144530f,-0.071637f,0.021639f,
0.108759f,0.164931f,0.174174f,0.133857f,0.055452f,-0.038732f,-0.121895f,-0.170373f,0.169165f,0.112146f,
0.017327f,-0.083332f,-0.155903f,-0.175925f,-0.136650f,-0.051316f,0.051316f,0.136650f,0.175925f,0.155903f,
0.083332f,-0.017327f,-0.112146f,-0.169165f,-0.169165f,-0.112146f,-0.017327f,0.083332f,0.155903f,0.175925f,
0.136650f,0.051316f,-0.051316f,-0.136650f,-0.175925f,-0.155903f,-0.083332f,0.017327f,0.112146f,0.169165f,
0.169165f,0.112146f,0.017327f,-0.083332f,-0.155903f,-0.175925f,-0.136650f,-0.051316f,0.051316f,0.136650f,
0.175925f,0.155903f,0.083332f,-0.017327f,-0.112146f,-0.169165f,-0.169165f,-0.112146f,-0.017327f,0.083332f,
0.155903f,0.175925f,0.136650f,0.051316f,-0.051316f,-0.136650f,-0.175925f,-0.155903f,-0.083332f,0.017327f,
0.112146f,0.169165f,0.167854f,0.101789f,-0.004338f,-0.108759f,-0.170373f,-0.164931f,-0.094575f,0.013005f,
0.115466f,0.172481f,0.161611f,0.087133f,-0.021639f,-0.121895f,-0.174174f,-0.157901f,-0.079481f,0.030222f,
0.128030f,0.175447f,0.153811f,0.071637f,-0.038732f,-0.133857f,-0.176298f,-0.149350f,-0.063621f,0.047149f,
0.139361f,0.176723f,0.144530f,0.055452f,-0.055452f,-0.144530f,-0.176723f,-0.139361f,-0.047149f,0.063621f,
0.149350f,0.176298f,0.133857f,0.038732f,-0.071637f,-0.153811f,-0.175447f,-0.128030f,-0.030222f,0.079481f,
0.157901f,0.174174f,0.121895f,0.021639f,-0.087133f,-0.161611f,-0.172481f,-0.115466f,-0.013005f,0.094575f,
0.164931f,0.170373f,0.108759f,0.004338f,-0.101789f,-0.167854f,0.166443f,0.090881f,-0.025939f,-0.130983f,
-0.176564f,-0.141988f,-0.042953f,0.075582f,0.159804f,0.171479f,0.105306f,-0.008674f,-0.118716f,-0.174863f,
-0.151626f,-0.059554f,0.059554f,0.151626f,0.174863f,0.118716f,0.008674f,-0.105306f,-0.171479f,-0.159804f,
-0.075582f,0.042953f,0.141988f,0.176564f,0.130983f,0.025939f,-0.090881f,-0.166443f,-0.166443f,-0.090881f,
0.025939f,0.130983f,0.176564f,0.141988f,0.042953f,-0.075582f,-0.159804f,-0.171479f,-0.105306f,0.008674f,
0.118716f,0.174863f,0.151626f,0.059554f,-0.059554f,-0.151626f,-0.174863f,-0.118716f,-0.008674f,0.105306f,
0.171479f,0.159804f,0.075582f,-0.042953f,-0.141988f,-0.176564f,-0.130983f,-0.025939f,0.090881f,0.166443f,
0.164931f,0.079481f,-0.047149f,-0.149350f,-0.174174f,-0.108759f,0.013005f,0.128030f,0.176723f,0.133857f,
0.021639f,-0.101789f,-0.172481f,-0.153811f,-0.055452f,0.071637f,0.161611f,0.167854f,0.087133f,-0.038732f,
-0.144530f,-0.175447f,-0.115466f,0.004338f,0.121895f,0.176298f,0.139361f,0.030222f,-0.094575f,-0.170373f,
-0.157901f,-0.063621f,0.063621f,0.157901f,0.170373f,0.094575f,-0.030222f,-0.139361f,-0.176298f,-0.121895f,
-0.004338f,0.115466f,0.175447f,0.144530f,0.038732f,-0.087133f,-0.167854f,-0.161611f,-0.071637f,0.055452f,
0.153811f,0.172481f,0.101789f,-0.021639f,-0.133857f,-0.176723f,-0.128030f,-0.013005f,0.108759f,0.174174f,
0.149350f,0.047149f,-0.079481f,-0.164931f,0.163320f,0.067650f,-0.067650f,-0.163320f,-0.163320f,-0.067650f,
0.067650f,0.163320f,0.163320f,0.067650f,-0.067650f,-0.163320f,-0.163320f,-0.067650f,0.067650f,0.163320f,
0.163320f,0.067650f,-0.067650f,-0.163320f,-0.163320f,-0.067650f,0.067650f,0.163320f,0.163320f,0.067650f,
-0.067650f,-0.163320f,-0.163320f,-0.067650f,0.067650f,0.163320f,0.163320f,0.067650f,-0.067650f,-0.163320f,
-0.163320f,-0.067650f,0.067650f,0.163320f,0.163320f,0.067650f,-0.067650f,-0.163320f,-0.163320f,-0.067650f,
0.067650f,0.163320f,0.163320f,0.067650f,-0.067650f,-0.163320f,-0.163320f,-0.067650f,0.067650f,0.163320f,
0.163320f,0.067650f,-0.067650f,-0.163320f,-0.163320f,-0.067650f,0.067650f,0.163320f,0.161611f,0.055452f,
-0.087133f,-0.172481f,-0.144530f,-0.021639f,0.115466f,0.176723f,0.121895f,-0.013005f,-0.139361f,-0.174174f,
-0.094575f,0.047149f,0.157901f,0.164931f,0.063621f,-0.079481f,-0.170373f,-0.149350f,-0.030222f,0.108759f,
0.176298f,0.128030f,-0.004338f,-0.133857f,-0.175447f,-0.101789f,0.038732f,0.153811f,0.167854f,0.071637f,
-0.071637f,-0.167854f,-0.153811f,-0.038732f,0.101789f,0.175447f,0.133857f,0.004338f,-0.128030f,-0.176298f,
-0.108759f,0.030222f,0.149350f,0.170373f,0.079481f,-0.063621f,-0.164931f,-0.157901f,-0.047149f,0.094575f,
0.174174f,0.139361f,0.013005f,-0.121895f,-0.176723f,-0.115466f,0.021639f,0.144530f,0.172481f,0.087133f,
-0.055452f,-0.161611f,0.159804f,0.042953f,-0.105306f,-0.176564f,-0.118716f,0.025939f,0.151626f,0.166443f,
0.059554f,-0.090881f,-0.174863f,-0.130983f,0.008674f,0.141988f,0.171479f,0.075582f,-0.075582f,-0.171479f,
-0.141988f,-0.008674f,0.130983f,0.174863f,0.090881f,-0.059554f,-0.166443f,-0.151626f,-0.025939f,0.118716f,
0.176564f,0.105306f,-0.042953f,-0.159804f,-0.159804f,-0.042953f,0.105306f,0.176564f,0.118716f,-0.025939f,
-0.151626f,-0.166443f,-0.059554f,0.090881f,0.174863f,0.130983f,-0.008674f,-0.141988f,-0.171479f,-0.075582f,
0.075582f,0.171479f,0.141988f,0.008674f,-0.130983f,-0.174863f,-0.090881f,0.059554f,0.166443f,0.151626f,
0.025939f,-0.118716f,-0.176564f,-0.105306f,0.042953f,0.159804f,0.157901f,0.030222f,-0.121895f,-0.175447f,
-0.087133f,0.071637f,0.172481f,0.133857f,-0.013005f,-0.149350f,-0.164931f,-0.047149f,0.108759f,0.176723f,
0.101789f,-0.055452f,-0.167854f,-0.144530f,-0.004338f,0.139361f,0.170373f,0.063621f,-0.094575f,-0.176298f,
-0.115466f,0.038732f,0.161611f,0.153811f,0.021639f,-0.128030f,-0.174174f,-0.079481f,0.079481f,0.174174f,
0.128030f,-0.021639f,-0.153811f,-0.161611f,-0.038732f,0.115466f,0.176298f,0.094575f,-0.063621f,-0.170373f,
-0.139361f,0.004338f,0.144530f,0.167854f,0.055452f,-0.101789f,-0.176723f,-0.108759f,0.047149f,0.164931f,
0.149350f,0.013005f,-0.133857f,-0.172481f,-0.071637f,0.087133f,0.175447f,0.121895f,-0.030222f,-0.157901f,
0.155903f,0.017327f,-0.136650f,-0.169165f,-0.051316f,0.112146f,0.175925f,0.083332f,-0.083332f,-0.175925f,
-0.112146f,0.051316f,0.169165f,0.136650f,-0.017327f,-0.155903f,-0.155903f,-0.017327f,0.136650f,0.169165f,
0.051316f,-0.112146f,-0.175925f,-0.083332f,0.083332f,0.175925f,0.112146f,-0.051316f,-0.169165f,-0.136650f,
0.017327f,0.155903f,0.155903f,0.017327f,-0.136650f,-0.169165f,-0.051316f,0.112146f,0.175925f,0.083332f,
-0.083332f,-0.175925f,-0.112146f,0.051316f,0.169165f,0.136650f,-0.017327f,-0.155903f,-0.155903f,-0.017327f,
0.136650f,0.169165f,0.051316f,-0.112146f,-0.175925f,-0.083332f,0.083332f,0.175925f,0.112146f,-0.051316f,
-0.169165f,-0.136650f,0.017327f,0.155903f,0.153811f,0.004338f,-0.149350f,-0.157901f,-0.013005f,0.144530f,
0.161611f,0.021639f,-0.139361f,-0.164931f,-0.030222f,0.133857f,0.167854f,0.038732f,-0.128030f,-0.170373f,
-0.047149f,0.121895f,0.172481f,0.055452f,-0.115466f,-0.174174f,-0.063621f,0.108759f,0.175447f,0.071637f,
-0.101789f,-0.176298f,-0.079481f,0.094575f,0.176723f,0.087133f,-0.087133f,-0.176723f,-0.094575f,0.079481f,
0.176298f,0.101789f,-0.071637f,-0.175447f,-0.108759f,0.063621f,0.174174f,0.115466f,-0.055452f,-0.172481f,
-0.121895f,0.047149f,0.170373f,0.128030f,-0.038732f,-0.167854f,-0.133857f,0.030222f,0.164931f,0.139361f,
-0.021639f,-0.161611f,-0.144530f,0.013005f,0.157901f,0.149350f,-0.004338f,-0.153811f,0.151626f,-0.008674f,
-0.159804f,-0.141988f,0.025939f,0.166443f,0.130983f,-0.042953f,-0.171479f,-0.118716f,0.059554f,0.174863f,
0.105306f,-0.075582f,-0.176564f,-0.090881f,0.090881f,0.176564f,0.075582f,-0.105306f,-0.174863f,-0.059554f,
0.118716f,0.171479f,0.042953f,-0.130983f,-0.166443f,-0.025939f,0.141988f,0.159804f,0.008674f,-0.151626f,
-0.151626f,0.008674f,0.159804f,0.141988f,-0.025939f,-0.166443f,-0.130983f,0.042953f,0.171479f,0.118716f,
-0.059554f,-0.174863f,-0.105306f,0.075582f,0.176564f,0.090881f,-0.090881f,-0.176564f,-0.075582f,0.105306f,
0.174863f,0.059554f,-0.118716f,-0.171479f,-0.042953f,0.130983f,0.166443f,0.025939f,-0.141988f,-0.159804f,
-0.008674f,0.151626f,0.149350f,-0.021639f,-0.167854f,-0.121895f,0.063621f,0.176298f,0.087133f,-0.101789f,
-0.174174f,-0.047149f,0.133857f,0.161611f,0.004338f,-0.157901f,-0.139361f,0.038732f,0.172481f,0.108759f,
-0.079481f,-0.176723f,-0.071637f,0.115466f,0.170373f,0.030222f,-0.144530f,-0.153811f,0.013005f,0.164931f,
0.128030f,-0.055452f,-0.175447f,-0.094575f,0.094575f,0.175447f,0.055452f,-0.128030f,-0.164931f,-0.013005f,
0.153811f,0.144530f,-0.030222f,-0.170373f,-0.115466f,0.071637f,0.176723f,0.079481f,-0.108759f,-0.172481f,
-0.038732f,0.139361f,0.157901f,-0.004338f,-0.161611f,-0.133857f,0.047149f,0.174174f,0.101789f,-0.087133f,
-0.176298f,-0.063621f,0.121895f,0.167854f,0.021639f,-0.149350f,0.146984f,-0.034487f,-0.173380f,-0.098212f,
0.098212f,0.173380f,0.034487f,-0.146984f,-0.146984f,0.034487f,0.173380f,0.098212f,-0.098212f,-0.173380f,
-0.034487f,0.146984f,0.146984f,-0.034487f,-0.173380f,-0.098212f,0.098212f,0.173380f,0.034487f,-0.146984f,
-0.146984f,0.034487f,0.173380f,0.098212f,-0.098212f,-0.173380f,-0.034487f,0.146984f,0.146984f,-0.034487f,
-0.173380f,-0.098212f,0.098212f,0.173380f,0.034487f,-0.146984f,-0.146984f,0.034487f,0.173380f,0.098212f,
-0.098212f,-0.173380f,-0.034487f,0.146984f,0.146984f,-0.034487f,-0.173380f,-0.098212f,0.098212f,0.173380f,
0.034487f,-0.146984f,-0.146984f,0.034487f,0.173380f,0.098212f,-0.098212f,-0.173380f,-0.034487f,0.146984f,
0.144530f,-0.047149f,-0.176298f,-0.071637f,0.128030f,0.157901f,-0.021639f,-0.172481f,-0.094575f,0.108759f,
0.167854f,0.004338f,-0.164931f,-0.115466f,0.087133f,0.174174f,0.030222f,-0.153811f,-0.133857f,0.063621f,
0.176723f,0.055452f,-0.139361f,-0.149350f,0.038732f,0.175447f,0.079481f,-0.121895f,-0.161611f,0.013005f,
0.170373f,0.101789f,-0.101789f,-0.170373f,-0.013005f,0.161611f,0.121895f,-0.079481f,-0.175447f,-0.038732f,
0.149350f,0.139361f,-0.055452f,-0.176723f,-0.063621f,0.133857f,0.153811f,-0.030222f,-0.174174f,-0.087133f,
0.115466f,0.164931f,-0.004338f,-0.167854f,-0.108759f,0.094575f,0.172481f,0.021639f,-0.157901f,-0.128030f,
0.071637f,0.176298f,0.047149f,-0.144530f,0.141988f,-0.059554f,-0.176564f,-0.042953f,0.151626f,0.130983f,
-0.075582f,-0.174863f,-0.025939f,0.159804f,0.118716f,-0.090881f,-0.171479f,-0.008674f,0.166443f,0.105306f,
-0.105306f,-0.166443f,0.008674f,0.171479f,0.090881f,-0.118716f,-0.159804f,0.025939f,0.174863f,0.075582f,
-0.130983f,-0.151626f,0.042953f,0.176564f,0.059554f,-0.141988f,-0.141988f,0.059554f,0.176564f,0.042953f,
-0.151626f,-0.130983f,0.075582f,0.174863f,0.025939f,-0.159804f,-0.118716f,0.090881f,0.171479f,0.008674f,
-0.166443f,-0.105306f,0.105306f,0.166443f,-0.008674f,-0.171479f,-0.090881f,0.118716f,0.159804f,-0.025939f,
-0.174863f,-0.075582f,0.130983f,0.151626f,-0.042953f,-0.176564f,-0.059554f,0.141988f,0.139361f,-0.071637f,
-0.174174f,-0.013005f,0.167854f,0.094575f,-0.121895f,-0.153811f,0.047149f,0.176723f,0.038732f,-0.157901f,
-0.115466f,0.101789f,0.164931f,-0.021639f,-0.175447f,-0.063621f,0.144530f,0.133857f,-0.079481f,-0.172481f,
-0.004338f,0.170373f,0.087133f,-0.128030f,-0.149350f,0.055452f,0.176298f,0.030222f,-0.161611f,-0.108759f,
0.108759f,0.161611f,-0.030222f,-0.176298f,-0.055452f,0.149350f,0.128030f,-0.087133f,-0.170373f,0.004338f,
0.172481f,0.079481f,-0.133857f,-0.144530f,0.063621f,0.175447f,0.021639f,-0.164931f,-0.101789f,0.115466f,
0.157901f,-0.038732f,-0.176723f,-0.047149f,0.153811f,0.121895f,-0.094575f,-0.167854f,0.013005f,0.174174f,
0.071637f,-0.139361f,0.136650f,-0.083332f,-0.169165f,0.017327f,0.175925f,0.051316f,-0.155903f,-0.112146f,
0.112146f,0.155903f,-0.051316f,-0.175925f,-0.017327f,0.169165f,0.083332f,-0.136650f,-0.136650f,0.083332f,
0.169165f,-0.017327f,-0.175925f,-0.051316f,0.155903f,0.112146f,-0.112146f,-0.155903f,0.051316f,0.175925f,
0.017327f,-0.169165f,-0.083332f,0.136650f,0.136650f,-0.083332f,-0.169165f,0.017327f,0.175925f,0.051316f,
-0.155903f,-0.112146f,0.112146f,0.155903f,-0.051316f,-0.175925f,-0.017327f,0.169165f,0.083332f,-0.136650f,
-0.136650f,0.083332f,0.169165f,-0.017327f,-0.175925f,-0.051316f,0.155903f,0.112146f,-0.112146f,-0.155903f,
0.051316f,0.175925f,0.017327f,-0.169165f,-0.083332f,0.136650f,0.133857f,-0.094575f,-0.161611f,0.047149f,
0.175447f,0.004338f,-0.174174f,-0.055452f,0.157901f,0.101789f,-0.128030f,-0.139361f,0.087133f,0.164931f,
-0.038732f,-0.176298f,-0.013005f,0.172481f,0.063621f,-0.153811f,-0.108759f,0.121895f,0.144530f,-0.079481f,
-0.167854f,0.030222f,0.176723f,0.021639f,-0.170373f,-0.071637f,0.149350f,0.115466f,-0.115466f,-0.149350f,
0.071637f,0.170373f,-0.021639f,-0.176723f,-0.030222f,0.167854f,0.079481f,-0.144530f,-0.121895f,0.108759f,
0.153811f,-0.063621f,-0.172481f,0.013005f,0.176298f,0.038732f,-0.164931f,-0.087133f,0.139361f,0.128030f,
-0.101789f,-0.157901f,0.055452f,0.174174f,-0.004338f,-0.175447f,-0.047149f,0.161611f,0.094575f,-0.133857f,
0.130983f,-0.105306f,-0.151626f,0.075582f,0.166443f,-0.042953f,-0.174863f,0.008674f,0.176564f,0.025939f,
-0.171479f,-0.059554f,0.159804f,0.090881f,-0.141988f,-0.118716f,0.118716f,0.141988f,-0.090881f,-0.159804f,
0.059554f,0.171479f,-0.025939f,-0.176564f,-0.008674f,0.174863f,0.042953f,-0.166443f,-0.075582f,0.151626f,
0.105306f,-0.130983f,-0.130983f,0.105306f,0.151626f,-0.075582f,-0.166443f,0.042953f,0.174863f,-0.008674f,
-0.176564f,-0.025939f,0.171479f,0.059554f,-0.159804f,-0.090881f,0.141988f,0.118716f,-0.118716f,-0.141988f,
0.090881f,0.159804f,-0.059554f,-0.171479f,0.025939f,0.176564f,0.008674f,-0.174863f,-0.042953f,0.166443f,
0.075582f,-0.151626f,-0.105306f,0.130983f,0.128030f,-0.115466f,-0.139361f,0.101789f,0.149350f,-0.087133f,
-0.157901f,0.071637f,0.164931f,-0.055452f,-0.170373f,0.038732f,0.174174f,-0.021639f,-0.176298f,0.004338f,
0.176723f,0.013005f,-0.175447f,-0.030222f,0.172481f,0.047149f,-0.167854f,-0.063621f,0.161611f,0.079481f,
-0.153811f,-0.094575f,0.144530f,0.108759f,-0.133857f,-0.121895f,0.121895f,0.133857f,-0.108759f,-0.144530f,
0.094575f,0.153811f,-0.079481f,-0.161611f,0.063621f,0.167854f,-0.047149f,-0.172481f,0.030222f,0.175447f,
-0.013005f,-0.176723f,-0.004338f,0.176298f,0.021639f,-0.174174f,-0.038732f,0.170373f,0.055452f,-0.164931f,
-0.071637f,0.157901f,0.087133f,-0.149350f,-0.101789f,0.139361f,0.115466f,-0.128030f};





const float32_t mfcc_window_coefs_config1_f32[NB_MFCC_WIN_COEFS_CONFIG1_F32]={
0.000000f,0.000062f,0.000247f,0.000555f,0.000987f,0.001541f,0.002219f,0.003020f,0.003943f,0.004988f,
0.006156f,0.007445f,0.008856f,0.010389f,0.012042f,0.013815f,0.015708f,0.017721f,0.019853f,0.022103f,
0.024472f,0.026957f,0.029560f,0.032278f,0.035112f,0.038060f,0.041123f,0.044298f,0.047586f,0.050986f,
0.054497f,0.058117f,0.061847f,0.065684f,0.069629f,0.073680f,0.077836f,0.082096f,0.086460f,0.090925f,
0.095492f,0.100158f,0.104922f,0.109785f,0.114743f,0.119797f,0.124944f,0.130184f,0.135516f,0.140937f,
0.146447f,0.152044f,0.157726f,0.163494f,0.169344f,0.175276f,0.181288f,0.187379f,0.193546f,0.199790f,
0.206107f,0.212497f,0.218958f,0.225489f,0.232087f,0.238751f,0.245479f,0.252271f,0.259123f,0.266035f,
0.273005f,0.280030f,0.287110f,0.294243f,0.301426f,0.308658f,0.315938f,0.323263f,0.330631f,0.338041f,
0.345491f,0.352980f,0.360504f,0.368063f,0.375655f,0.383277f,0.390928f,0.398606f,0.406309f,0.414035f,
0.421783f,0.429549f,0.437333f,0.445133f,0.452946f,0.460770f,0.468605f,0.476447f,0.484295f,0.492146f,
0.500000f,0.507854f,0.515705f,0.523553f,0.531395f,0.539230f,0.547054f,0.554867f,0.562667f,0.570451f,
0.578217f,0.585965f,0.593691f,0.601394f,0.609072f,0.616723f,0.624345f,0.631937f,0.639496f,0.647020f,
0.654508f,0.661959f,0.669369f,0.676737f,0.684062f,0.691342f,0.698574f,0.705757f,0.712890f,0.719970f,
0.726995f,0.733965f,0.740877f,0.747729f,0.754521f,0.761249f,0.767913f,0.774511f,0.781042f,0.787503f,
0.793893f,0.800210f,0.806454f,0.812621f,0.818712f,0.824724f,0.830656f,0.836506f,0.842274f,0.847956f,
0.853553f,0.859063f,0.864484f,0.869816f,0.875056f,0.880203f,0.885257f,0.890215f,0.895078f,0.899842f,
0.904508f,0.909075f,0.913540f,0.917904f,0.922164f,0.926320f,0.930371f,0.934316f,0.938153f,0.941883f,
0.945503f,0.949014f,0.952413f,0.955702f,0.958877f,0.961940f,0.964888f,0.967722f,0.970440f,0.973043f,
0.975528f,0.977897f,0.980147f,0.982279f,0.984292f,0.986185f,0.987958f,0.989611f,0.991144f,0.992555f,
0.993844f,0.995012f,0.996057f,0.996980f,0.997781f,0.998459f,0.999013f,0.999445f,0.999753f,0.999938f,
1.000000f,0.999938f,0.999753f,0.999445f,0.999013f,0.998459f,0.997781f,0.996980f,0.996057f,0.995012f,
0.993844f,0.992555f,0.991144f,0.989611f,0.987958f,0.986185f,0.984292f,0.982279f,0.980147f,0.977897f,
0.975528f,0.973043f,0.970440f,0.967722f,0.964888f,0.961940f,0.958877f,0.955702f,0.952413f,0.949014f,
0.945503f,0.941883f,0.938153f,0.934316f,0.930371f,0.926320f,0.922164f,0.917904f,0.913540f,0.909075f,
0.904508f,0.899842f,0.895078f,0.890215f,0.885257f,0.880203f,0.875056f,0.869816f,0.864484f,0.859063f,
0.853553f,0.847956f,0.842274f,0.836506f,0.830656f,0.824724f,0.818712f,0.812621f,0.806454f,0.800210f,
0.793893f,0.787503f,0.781042f,0.774511f,0.767913f,0.761249f,0.754521f,0.747729f,0.740877f,0.733965f,
0.726995f,0.719970f,0.712890f,0.705757f,0.698574f,0.691342f,0.684062f,0.676737f,0.669369f,0.661959f,
0.654508f,0.647020f,0.639496f,0.631937f,0.624345f,0.616723f,0.609072f,0.601394f,0.593691f,0.585965f,
0.578217f,0.570451f,0.562667f,0.554867f,0.547054f,0.539230f,0.531395f,0.523553f,0.515705f,0.507854f,
0.500000f,0.492146f,0.484295f,0.476447f,0.468605f,0.460770f,0.452946f,0.445133f,0.437333f,0.429549f,
0.421783f,0.414035f,0.406309f,0.398606f,0.390928f,0.383277f,0.375655f,0.368063f,0.360504f,0.352980f,
0.345491f,0.338041f,0.330631f,0.323263f,0.315938f,0.308658f,0.301426f,0.294243f,0.287110f,0.280030f,
0.273005f,0.266035f,0.259123f,0.252271f,0.245479f,0.238751f,0.232087f,0.225489f,0.218958f,0.212497f,
0.206107f,0.199790f,0.193546f,0.187379f,0.181288f,0.175276f,0.169344f,0.163494f,0.157726f,0.152044f,
0.146447f,0.140937f,0.135516f,0.130184f,0.124944f,0.119797f,0.114743f,0.109785f,0.104922f,0.100158f,
0.095492f,0.090925f,0.086460f,0.082096f,0.077836f,0.073680f,0.069629f,0.065684f,0.061847f,0.058117f,
0.054497f,0.050986f,0.047586f,0.044298f,0.041123f,0.038060f,0.035112f,0.032278f,0.029560f,0.026957f,
0.024472f,0.022103f,0.019853f,0.017721f,0.015708f,0.013815f,0.012042f,0.010389f,0.008856f,0.007445f,
0.006156f,0.004988f,0.003943f,0.003020f,0.002219f,0.001541f,0.000987f,0.000555f,0.000247f,0.000062f,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0};



const uint32_t mfcc_filter_pos_config1_f32[NB_MFCC_NB_FILTER_CONFIG1_F32]={
1,1,2,3,4,5,6,7,9,10,
11,12,14,15,17,18,20,21,23,25,
27,29,31,33,35,37,39,42,44,47,
50,53,56,59,62,65,69,72,76,80,
84,88,92,97,101,106,111,117,122,128,
134,140,146,153,160,167,174,182,190,199,
207,217,226,236};
const uint32_t mfcc_filter_len_config1_f32[NB_MFCC_NB_FILTER_CONFIG1_F32]={
1,2,2,2,2,2,3,3,2,2,
3,3,3,3,3,3,3,4,4,4,
4,4,4,4,4,5,5,5,6,6,
6,6,6,6,7,7,7,8,8,8,
8,9,9,9,10,11,11,11,12,12,
12,13,14,14,14,15,16,17,17,18,
19,19,20,20};




const float32_t mfcc_filter_coefs_config1_f32[NB_MFCC_FILTER_COEFS_CONFIG1_F32]={
0.873460f,0.126540f,0.794069f,0.205931f,0.758039f,0.241961f,0.762021f,0.237979f,0.803038f,0.196962f,
0.878435f,0.121565f,0.985831f,0.123086f,0.014169f,0.876914f,0.288267f,0.711734f,0.479621f,0.520379f,
0.695559f,0.304441f,0.934628f,0.195504f,0.065372f,0.804496f,0.476971f,0.523029f,0.777913f,0.097301f,
0.222087f,0.902699f,0.434188f,0.565812f,0.787697f,0.157013f,0.212303f,0.842987f,0.541383f,0.458617f,
0.940105f,0.352524f,0.059895f,0.647476f,0.778031f,0.216055f,0.221969f,0.783945f,0.666063f,0.127553f,
0.333937f,0.872447f,0.600057f,0.083132f,0.399943f,0.916868f,0.576364f,0.079361f,0.423636f,0.920639f,
0.591753f,0.113193f,0.408247f,0.886807f,0.643350f,0.181912f,0.356650f,0.818088f,0.728585f,0.283087f,
0.271415f,0.716913f,0.845153f,0.414531f,0.154847f,0.585469f,0.990980f,0.574272f,0.164189f,0.009020f,
0.425728f,0.835811f,0.760524f,0.363079f,0.239476f,0.636921f,0.971665f,0.586103f,0.206218f,0.028335f,
0.413897f,0.793782f,0.831848f,0.462833f,0.099024f,0.168152f,0.537167f,0.900976f,0.740274f,0.386446f,
0.037406f,0.259726f,0.613554f,0.962594f,0.693026f,0.353184f,0.017761f,0.306974f,0.646816f,0.982239f,
0.686643f,0.359723f,0.036894f,0.313357f,0.640277f,0.963106f,0.718056f,0.403111f,0.091966f,0.281944f,
0.596889f,0.908034f,0.784528f,0.480713f,0.180434f,0.215472f,0.519287f,0.819566f,0.883610f,0.590164f,
0.300018f,0.013100f,0.116390f,0.409836f,0.699982f,0.986900f,0.729338f,0.448664f,0.171012f,0.270662f,
0.551336f,0.828988f,0.896316f,0.624515f,0.355549f,0.089358f,0.103684f,0.375485f,0.644451f,0.910642f,
0.825886f,0.565078f,0.306881f,0.051243f,0.174114f,0.434922f,0.693119f,0.948757f,0.798114f,0.547444f,
0.299188f,0.053298f,0.201886f,0.452556f,0.700812f,0.946702f,0.809729f,0.568440f,0.329387f,0.092528f,
0.190271f,0.431560f,0.670614f,0.907472f,0.857825f,0.625239f,0.394731f,0.166265f,0.142175f,0.374761f,
0.605269f,0.833735f,0.939804f,0.715315f,0.492762f,0.272114f,0.053337f,0.060196f,0.284685f,0.507238f,
0.727886f,0.946663f,0.836399f,0.621272f,0.407923f,0.196325f,0.163601f,0.378728f,0.592077f,0.803675f,
0.986449f,0.778266f,0.571751f,0.366875f,0.163614f,0.013551f,0.221734f,0.428249f,0.633125f,0.836386f,
0.961943f,0.761836f,0.563269f,0.366219f,0.170664f,0.038057f,0.238164f,0.436731f,0.633781f,0.829336f,
0.976579f,0.783945f,0.592738f,0.402938f,0.214525f,0.027478f,0.023421f,0.216055f,0.407262f,0.597062f,
0.785475f,0.972522f,0.841777f,0.657404f,0.474340f,0.292566f,0.112063f,0.158223f,0.342596f,0.525660f,
0.707434f,0.887937f,0.932815f,0.754805f,0.578014f,0.402427f,0.228027f,0.054798f,0.067185f,0.245195f,
0.421986f,0.597573f,0.771973f,0.945202f,0.882725f,0.711792f,0.541984f,0.373287f,0.205686f,0.039168f,
0.117275f,0.288208f,0.458016f,0.626713f,0.794314f,0.960832f,0.873717f,0.709321f,0.545966f,0.383639f,
0.222327f,0.062018f,0.126283f,0.290679f,0.454034f,0.616361f,0.777673f,0.937982f,0.902699f,0.744358f,
0.586983f,0.430562f,0.275084f,0.120538f,0.097301f,0.255642f,0.413017f,0.569438f,0.724916f,0.879462f,
0.966913f,0.814197f,0.662379f,0.511451f,0.361400f,0.212217f,0.063892f,0.033087f,0.185803f,0.337621f,
0.488549f,0.638600f,0.787783f,0.936108f,0.916414f,0.769776f,0.623966f,0.478976f,0.334796f,0.191418f,
0.048832f,0.083586f,0.230224f,0.376034f,0.521024f,0.665204f,0.808582f,0.951168f,0.907031f,0.766004f,
0.625745f,0.486244f,0.347493f,0.209485f,0.072211f,0.092969f,0.233996f,0.374255f,0.513756f,0.652507f,
0.790515f,0.927789f,0.935664f,0.799836f,0.664720f,0.530307f,0.396592f,0.263566f,0.131223f,0.064336f,
0.200164f,0.335280f,0.469693f,0.603408f,0.736434f,0.868777f,0.999555f,0.868556f,0.738218f,0.608537f,
0.479503f,0.351113f,0.223358f,0.096232f,0.000445f,0.131444f,0.261782f,0.391463f,0.520497f,0.648887f,
0.776642f,0.903768f,0.969730f,0.843846f,0.718573f,0.593905f,0.469837f,0.346363f,0.223478f,0.101175f,
0.030270f,0.156154f,0.281427f,0.406095f,0.530163f,0.653637f,0.776522f,0.898825f,0.979449f,0.858295f,
0.737707f,0.617680f,0.498210f,0.379290f,0.260916f,0.143082f,0.025785f,0.020551f,0.141705f,0.262293f,
0.382320f,0.501790f,0.620710f,0.739084f,0.856918f,0.974215f,0.909018f,0.792778f,0.677059f,0.561857f,
0.447168f,0.332986f,0.219307f,0.106127f,0.090982f,0.207222f,0.322941f,0.438143f,0.552832f,0.667014f,
0.780693f,0.893873f,0.993441f,0.881246f,0.769537f,0.658309f,0.547559f,0.437282f,0.327475f,0.218133f,
0.109253f,0.000830f,0.006559f,0.118754f,0.230463f,0.341691f,0.452441f,0.562718f,0.672525f,0.781867f,
0.890747f,0.999170f,0.892862f,0.785343f,0.678271f,0.571641f,0.465451f,0.359695f,0.254372f,0.149477f,
0.045007f,0.107138f,0.214657f,0.321729f,0.428359f,0.534549f,0.640305f,0.745628f,0.850523f,0.954993f,
0.940958f,0.837327f,0.734111f,0.631306f,0.528910f,0.426918f,0.325328f,0.224136f,0.123340f,0.022937f,
0.059042f,0.162673f,0.265889f,0.368694f,0.471090f,0.573082f,0.674672f,0.775864f,0.876660f,0.977063f,
0.922922f,0.823294f,0.724049f,0.625185f,0.526698f,0.428586f,0.330846f,0.233474f,0.136469f,0.039827f,
0.077078f,0.176706f,0.275951f,0.374815f,0.473302f,0.571414f,0.669154f,0.766526f,0.863531f,0.960173f,
0.943546f,0.847623f,0.752055f,0.656841f,0.561976f,0.467459f,0.373287f,0.279457f,0.185968f,0.092816f
};





