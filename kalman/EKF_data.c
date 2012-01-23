/*
 * File: EKF_data.c
 *
 * Code generated for Simulink model 'EKF'.
 *
 * Model version                  : 1.635
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Mon Jan 23 23:51:26 2012
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EKF.h"
#include "EKF_private.h"

/* Block parameters (auto storage) */
Parameters_EKF EKF_P = {
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0 },

  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33333333333333331,
    0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.26666666666666666, 0.2, 0.0, -0.33333333333333331, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.25714285714285712, 0.22857142857142856,
    0.14285714285714285, 0.0, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25396825396825395, 0.23809523809523808, 0.19047619047619047,
    0.1111111111111111, 0.0, -0.14285714285714285, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.25252525252525254, 0.24242424242424243, 0.21212121212121213,
    0.16161616161616163, 0.090909090909090912, 0.0, -0.1111111111111111, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.25174825174825177, 0.24475524475524477,
    0.22377622377622378, 0.1888111888111888, 0.13986013986013987,
    0.076923076923076927, 0.0, -0.090909090909090912, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25128205128205128, 0.24615384615384617, 0.23076923076923078,
    0.20512820512820512, 0.16923076923076924, 0.12307692307692308,
    0.066666666666666666, 0.0, -0.076923076923076927, 0.0, 0.0, 0.0, 0.0,
    0.25098039215686274, 0.24705882352941178, 0.23529411764705882,
    0.21568627450980393, 0.18823529411764706, 0.15294117647058825,
    0.10980392156862745, 0.058823529411764705, 0.0, -0.066666666666666666, 0.0,
    0.0, 0.0, 0.25077399380804954, 0.24767801857585139, 0.23839009287925697,
    0.22291021671826625, 0.20123839009287925, 0.17337461300309598,
    0.13931888544891641, 0.099071207430340563, 0.052631578947368418, 0.0,
    -0.058823529411764705, 0.0, 0.0, 0.25062656641604009, 0.24812030075187969,
    0.24060150375939848, 0.22807017543859648, 0.21052631578947367,
    0.18796992481203006, 0.16040100250626566, 0.12781954887218044,
    0.090225563909774431, 0.047619047619047616, 0.0, -0.052631578947368418, 0.0,
    0.25051759834368531, 0.2484472049689441, 0.24223602484472051,
    0.2318840579710145, 0.21739130434782608, 0.19875776397515527,
    0.17598343685300208, 0.14906832298136646, 0.11801242236024845,
    0.082815734989648032, 0.043478260869565216, 0.0, -0.047619047619047616 },
  0.0,
  1.0,
  1.0,

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },
  1.0,
  1.0,
  1.0,
  0.0,
  0.0,
  0.5,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.33333333333333331,
    0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.26666666666666666, 0.2, 0.0, -0.33333333333333331, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.25714285714285712, 0.22857142857142856,
    0.14285714285714285, 0.0, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25396825396825395, 0.23809523809523808, 0.19047619047619047,
    0.1111111111111111, 0.0, -0.14285714285714285, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.25252525252525254, 0.24242424242424243, 0.21212121212121213,
    0.16161616161616163, 0.090909090909090912, 0.0, -0.1111111111111111, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.25174825174825177, 0.24475524475524477,
    0.22377622377622378, 0.1888111888111888, 0.13986013986013987,
    0.076923076923076927, 0.0, -0.090909090909090912, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.25128205128205128, 0.24615384615384617, 0.23076923076923078,
    0.20512820512820512, 0.16923076923076924, 0.12307692307692308,
    0.066666666666666666, 0.0, -0.076923076923076927, 0.0, 0.0, 0.0, 0.0,
    0.25098039215686274, 0.24705882352941178, 0.23529411764705882,
    0.21568627450980393, 0.18823529411764706, 0.15294117647058825,
    0.10980392156862745, 0.058823529411764705, 0.0, -0.066666666666666666, 0.0,
    0.0, 0.0, 0.25077399380804954, 0.24767801857585139, 0.23839009287925697,
    0.22291021671826625, 0.20123839009287925, 0.17337461300309598,
    0.13931888544891641, 0.099071207430340563, 0.052631578947368418, 0.0,
    -0.058823529411764705, 0.0, 0.0, 0.25062656641604009, 0.24812030075187969,
    0.24060150375939848, 0.22807017543859648, 0.21052631578947367,
    0.18796992481203006, 0.16040100250626566, 0.12781954887218044,
    0.090225563909774431, 0.047619047619047616, 0.0, -0.052631578947368418, 0.0,
    0.25051759834368531, 0.2484472049689441, 0.24223602484472051,
    0.2318840579710145, 0.21739130434782608, 0.19875776397515527,
    0.17598343685300208, 0.14906832298136646, 0.11801242236024845,
    0.082815734989648032, 0.043478260869565216, 0.0, -0.047619047619047616 },
  0.5,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  { 1.0, 1.0, 1.5, 2.5, 4.375, 7.875, 14.4375, 26.8125, 50.2734375, 94.9609375,
    180.42578125, 344.44921875, 660.1943359375, 0.0, 1.0, 1.7320508075688772,
    3.0618621784789726, 5.5339859052946636, 10.16658128379447,
    18.903124741692839, 35.469603513959669, 67.03125, 127.40346687426536,
    243.28607380714598, 466.38644692864216, 897.027461585248, 0.0, 0.0,
    0.8660254037844386, 1.9364916731037085, 3.9131189606246322,
    7.685213074469698, 14.944232269507859, 28.960809996010127,
    56.082367403612253, 108.65004161512664, 210.69192030396434,
    409.04797337487776, 795.12986069746626, 0.0, 0.0, 0.0, 0.79056941504209488,
    2.0916500663351889, 4.7062126492541738, 9.9628215130052382,
    20.478385136833914, 41.41957332816817, 82.982839993569982,
    165.28034045942309, 327.9680080977904, 649.22081265302029, 0.0, 0.0, 0.0,
    0.0, 0.739509972887452, 2.2185299186623553, 5.4568620790707172,
    12.348930874776167, 26.736219617835371, 56.375738371688975,
    116.87084953567937, 239.5139682335957, 486.91560948976519, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.7015607600201138, 2.3268138086232852, 6.1744654373880836,
    14.830586268334102, 33.69094768709671, 73.915615322315773,
    158.42359886807964, 334.02135244518831, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.671693289381396, 2.4218245962496963, 6.8652274293172546, 17.39793057467611,
    41.320085114855779, 94.117642301250768, 208.29891011946015, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.6472598492877496, 2.5068266169601756,
    7.5335249254737544, 20.043185339772048, 49.604352946160631,
    117.05388227149012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.6267066542400439, 2.5839777317091466, 8.1825961504123, 22.760038068635609,
    58.526941135745062, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.60904939217552367, 2.65478475211798, 8.8149248398872544,
    25.543251233216804, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.59362791713657326, 2.72034486491732, 9.4324706362690076, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.579979473934679,
    2.7814838439702596, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.56776801212685635 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },
  1.0,

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },

  { 0.0, 4944.4, -4689.8739716542486, -490.51032099233134, 1584.9335632763916,
    453.42952525723337, -393.18499462721104, -2053.6900434582649, 737.34375,
    -2611.77107092244, 681.20100666000872, 93.277289385728437,
    -807.32471542672329, -29496.6, -1586.3, -498.91723512021508,
    487.80225245482421, -826.45072448392227, 1451.736749767326,
    659.04064308529655, -611.07309091581374, -1121.647348072245,
    1249.4754785739563, -21.069192030396437, 695.38155473729216,
    238.53895820923987, -3594.8999999999996, 5241.3589487841791,
    1445.0499887547141, -424.21954811158815, 343.65810589887155,
    -556.27433514184338, 612.71352304982213, 133.10950338942044,
    492.89292260520125, 1062.1803519176958, 776.81760015928853,
    -196.78080485867423, 1363.3637065713426, 3350.25, -7122.5037995777857,
    2385.5640920964588, 501.22100913668817, -228.58253261951143, 0.0,
    -361.78995584238851, 307.48837878192654, -465.21022135033542,
    -405.90531627616065, 514.23173795698926, -431.12514282047226,
    -1217.289023724413, 3992.625, 4476.4411987928534, 652.3169307361261,
    -746.928238688296, 66.112191576138216, 70.787480686029483,
    7.2131228067321844, 43.221258061716583, 247.67079068117948,
    -249.31301288451567, -532.19243032067357, 142.58123898127167,
    167.01067622259416, -1818.3375, 3631.5028345713845, 1539.3481788162806,
    -664.046604809764, -361.62037674196392, -5.472173928156888,
    36.943130915976781, -67.084541316116585, 48.056592005220779,
    139.18344459740888, -41.320085114855779, -37.647056920500312,
    124.97934607167608, 1051.05, 1296.7543572801287, 1135.7616524825974,
    -1408.7429619389407, -124.41645540281236, 30.713942273827364,
    -52.32490724281076, -2.1359575026495734, -27.0737274631699,
    15.820402343494885, -78.16842282511098, -124.01088236540159, -0.0,
    2158.40625, -2663.767223898371, -136.1158069812476, 927.67084669857627,
    171.65013915938871, 64.214440548836066, 4.1171018136244832,
    3.1715732615099732, 1.0654013122080745, -15.762264163425794,
    -16.3651923008246, -29.588049489226293, 5.8526941135745068, 1226.671875,
    542.953125, -813.19432735237763, -231.94961063774173, -516.00903862422263,
    170.55174208584216, 74.830978979558083, -35.346255299138477,
    -2.3188146206881624, 4.2633457452286656, -5.30956950423596,
    -18.511342163763235, 7.6629753699650411, 512.7890625, 1197.5925886180944,
    369.41014149143058, -431.51076796656395, 174.76478895223582,
    -417.76775131999921, -12.178551402273277, 63.281609373979542,
    -21.963810719527746, -6.1513988609727885, -4.9271117122335584,
    -5.1686552433429078, -8.489223572642107, -360.8515625, -1532.7022649850196,
    189.6227282735679, -181.80837450536541, -23.374169907135876,
    184.78903830578943, -12.396025534456733, 44.095007747498506,
    25.366048066278129, -2.65478475211798, -1.6621581679824051,
    -1.0439630530824222, -0.556296768794052, 1033.34765625, -699.57967039296318,
    -859.00074408724333, 557.54561376624372, -119.75698411679785,
    79.211799434039818, -75.294113841000623, 19.841741178464254,
    40.9680685235441, 0.88149248398872548, 1.9042414054421237, 2.20392200095178,
    0.51099121091417077, -1452.4275390625, -179.40549231704961,
    238.53895820923987, 649.22081265302029, -292.14936569385912,
    300.61921720066948, -20.829891011946017, 58.526941135745062,
    -23.410776454298027, -10.217300493286722, 1.8864941272538016,
    -2.225187075176208, 0.0 },

  { 0.0, -25.9, -38.97114317029974, 22.3515939028965, 6.08738449582413,
    4.0666325135177877, -3.7806249483385681, 24.828722459771768, -6.703125, -0.0,
    24.3286073807146, -0.0, -0.0, 11.6, 16.5, -10.219099764656375,
    -7.5523175251044634, 10.565421193686507, 13.833383534045456,
    -31.382887765966505, 8.6882429988030374, 11.216473480722451,
    -21.730008323025331, -21.069192030396437, 40.904797337487778, 0.0, -18.15,
    -7.62102355330306, 1.6454482671904334, -2.055480479109447,
    8.1574352587072365, 5.647455179105008, -3.9851286052020956,
    -2.0478385136833914, 16.567829331267269, 0.0, 0.0, 0.0, -0.0, 1.0,
    -12.553634931763787, -5.6158258520007545, -6.08738449582413,
    -0.59160797830996159, 8.8741196746494211, -3.27411724744243,
    -1.2348930874776167, 10.694487847134148, -5.6375738371688975,
    -11.687084953567938, 23.951396823359573, 0.0, -7.875, 12.728167582177726,
    -34.044134957434295, 9.6215903051418685, -1.5529709430636494,
    -0.42093645601206825, 1.1634069043116426, -4.9395723499104669,
    1.4830586268334103, 3.3690947687096711, -7.3915615322315773, 0.0, -0.0,
    -7.875, 6.0999487702766819, -13.833383534045456, -4.7062126492541738,
    1.9966769267961197, 0.7015607600201138, 0.60452396044325651,
    -0.72654737887490883, -0.68652274293172555, -0.0, -0.0, 9.4117642301250779,
    20.829891011946017, -2.8875, -3.7806249483385681, -1.494423226950786,
    19.925643026010476, -9.27666553442022, -0.69804414258698555,
    1.1418785919483732, 0.19417795478632488, 1.0027306467840702,
    -1.5067049850947509, -2.0043185339772047, 0.0, 0.0, 2.6812500000000004,
    -3.5469603513959669, -17.376485997606075, 26.621900677884089,
    4.9395723499104669, 1.8523396312164251, -1.6952772173747872,
    0.38835590957264976, 0.18801199627201318, 0.775193319512744,
    -1.63651923008246, -2.2760038068635611, 0.0, -5.02734375, 6.703125,
    -33.649420442167347, 8.2839146656336347, -5.3472439235670741,
    4.44917588050023, 2.0595682287951762, -1.5040959701761054,
    0.12534133084800878, 0.12180987843510474, 0.0, -0.88149248398872548, -0.0,
    -0.0, -12.740346687426538, 0.0, 24.894851998070994, -22.55029534867559,
    -10.107284306129012, 1.739793057467611, -0.75335249254737546,
    -1.0335910926836587, -0.12180987843510474, -0.059362791713657326, -0.0, -0.0,
    0.0, -0.0, -21.069192030396437, 33.056068091884619, -0.0,
    -7.3915615322315773, -8.2640170229711565, 0.0, -0.81825961504123,
    -0.530956950423596, -0.11872558342731465, -0.0579979473934679, 0.0, 0.0, 0.0,
    -0.0, 32.796800809779043, -0.0, 0.0, -0.0, -0.0, -0.0, 0.0,
    -0.272034486491732, -0.0, 0.0, -0.0, 0.0, 79.512986069746631,
    64.922081265302026, -48.691560948976523, -0.0, 0.0, 0.0, -0.0, 0.0, 0.0,
    -0.278148384397026, 0.056776801212685635 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },
  1.0,

  { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0 },

  { 0.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0 },
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,

  { 0.0, 0.0, 0.0, 0.0 },
  6356.7523142,
  6378.137,
  2.0,
  1.0,

  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },
  0.0,
  11.0,
  1.0,

  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,
  0.0,

  { 0.003, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.003, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.003, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.003, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,
  0.0,
  1.0,
  -1.0,
  1.0,
  0.0,
  9.7803267714,
  1.0,
  0.00193185138639,
  0.0818191908426,
  0.5,
  2010.0,

  { 26.0, 5.0, 2011.0 },
  0.0027397260273972603,
  0.083333333333333329,
  -1000.0,
  180.0,
  -180.0,
  90.0,
  -90.0,
  0.017453292519943295,
  -1000.0,
  -1000.0,
  1.0,
  1.0E+6,
  0.0,
  0.001,
  -1000.0,
  6371.2,
  57.295779513082323,
  57.295779513082323,
  0.017453292519943295,
  1.0,
  1.0E-5,
  0.0,
  0.5,
  0.0,

  { 0.0, 0.0, 0.0 },

  { 0.0, 0.0, 0.0, 0.0 },
  -1.0,
  0.1,
  1.0,
  1.0,
  1.0,
  0.0,
  3.1415926535897931,
  -3.1415926535897931,
  1.0,
  -1.0,
  0.0,
  -1.0,
  57.295779513082323,
  0.5,
  1.5,
  6.378137E+6,
  0.0,
  1.0E+6,
  -90.0,
  90.0,
  -180.0,
  180.0,
  0.0,
  5.0,
  1.0,
  1.0,
  1,
  1,
  1,
  1,
  13,
  1,
  13,
  1,
  1,
  2,
  1,
  1,
  13,
  2,
  1,
  1,
  13,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  13,
  1,
  1,
  12,
  1
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
