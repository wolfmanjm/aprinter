/*
 * Copyright (c) 2013 Ambroz Bizjak
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* 
 * This file was automatically generated using gen_avr_thermistor_table.py.
 * The following parameters were used for generation:
 * 
 * Name = Extruder
 * ResistorR = 4700.0
 * ThermistorR0 = 100000.0
 * ThermistorBeta = 3960.0
 * StartTemp = 20.0
 * EndTemp = 300.0
 * NumBits = 13
 * ScaleFactorExp = 4
 * 
 * The file can be regenerated with the following command:
 * 
 * python gen_avr_thermistor_table.py "Extruder" 4700.0 100000.0 3960.0 20.0 300.0 13 4
 */

#ifndef AMBROLIB_AVR_THERMISTOR_Extruder_H
#define AMBROLIB_AVR_THERMISTOR_Extruder_H

#include <stdint.h>
#ifdef AMBROLIB_AVR
#include <avr/pgmspace.h>
#endif

#include <aprinter/meta/FixedPoint.h>
#include <aprinter/base/Likely.h>

#include <aprinter/BeginNamespace.h>

class AvrThermistorTable_Extruder {
public:
    using ValueFixedType = FixedPoint<13, false, -4>;
    
    static ValueFixedType call (uint16_t adc_value)
    {
        if (AMBRO_UNLIKELY(adc_value < 36)) {
            return ValueFixedType::maxValue();
        }
        if (AMBRO_UNLIKELY(adc_value > 988 - 1)) {
            return ValueFixedType::minValue();
        }
        return ValueFixedType::importBits(lookup(adc_value - 36));
    }
    
    static uint16_t invert (ValueFixedType temp_value, bool round_up)
    {
        uint16_t a = 0;
        uint16_t b = 952 - 1;
        if (temp_value > ValueFixedType::importBits(lookup(a))) {
            return 36 + a;
        }
        if (temp_value <= ValueFixedType::importBits(lookup(b))) {
            return 36 + b;
        }
        while (b - a > 1) {
            uint16_t c = a + (b - a) / 2;
            if (temp_value > ValueFixedType::importBits(lookup(c))) {
                b = c;
            } else {
                a = c;
            }
        }
        return 36 + ((temp_value == ValueFixedType::importBits(lookup(a)) || round_up) ? a : b);
    }
    
private:
    inline static uint16_t lookup (uint16_t i)
    {
#ifdef AMBROLIB_AVR
        return pgm_read_word(&table[i]);
#else
        return table[i];
#endif
    }

#ifdef AMBROLIB_AVR
    static uint16_t const table[952] PROGMEM;
#else
    static uint16_t const table[952];
#endif
};

#ifdef AMBROLIB_AVR
uint16_t const AvrThermistorTable_Extruder::table[952] PROGMEM = {
#else
uint16_t const AvrThermistorTable_Extruder::table[952] = {
#endif
UINT16_C(4796), UINT16_C(4758), UINT16_C(4722), UINT16_C(4687), UINT16_C(4653), 
UINT16_C(4620), UINT16_C(4588), UINT16_C(4557), UINT16_C(4527), UINT16_C(4498), UINT16_C(4469), UINT16_C(4441), UINT16_C(4414), 
UINT16_C(4388), UINT16_C(4362), UINT16_C(4337), UINT16_C(4313), UINT16_C(4289), UINT16_C(4266), UINT16_C(4243), UINT16_C(4221), 
UINT16_C(4199), UINT16_C(4178), UINT16_C(4157), UINT16_C(4137), UINT16_C(4117), UINT16_C(4097), UINT16_C(4078), UINT16_C(4059), 
UINT16_C(4040), UINT16_C(4022), UINT16_C(4004), UINT16_C(3987), UINT16_C(3970), UINT16_C(3953), UINT16_C(3936), UINT16_C(3920), 
UINT16_C(3904), UINT16_C(3888), UINT16_C(3872), UINT16_C(3857), UINT16_C(3842), UINT16_C(3827), UINT16_C(3812), UINT16_C(3798), 
UINT16_C(3784), UINT16_C(3770), UINT16_C(3756), UINT16_C(3743), UINT16_C(3729), UINT16_C(3716), UINT16_C(3703), UINT16_C(3690), 
UINT16_C(3677), UINT16_C(3665), UINT16_C(3653), UINT16_C(3640), UINT16_C(3628), UINT16_C(3617), UINT16_C(3605), UINT16_C(3593), 
UINT16_C(3582), UINT16_C(3571), UINT16_C(3559), UINT16_C(3548), UINT16_C(3537), UINT16_C(3527), UINT16_C(3516), UINT16_C(3505), 
UINT16_C(3495), UINT16_C(3485), UINT16_C(3475), UINT16_C(3464), UINT16_C(3454), UINT16_C(3445), UINT16_C(3435), UINT16_C(3425), 
UINT16_C(3416), UINT16_C(3406), UINT16_C(3397), UINT16_C(3387), UINT16_C(3378), UINT16_C(3369), UINT16_C(3360), UINT16_C(3351), 
UINT16_C(3342), UINT16_C(3334), UINT16_C(3325), UINT16_C(3316), UINT16_C(3308), UINT16_C(3299), UINT16_C(3291), UINT16_C(3283), 
UINT16_C(3275), UINT16_C(3266), UINT16_C(3258), UINT16_C(3250), UINT16_C(3242), UINT16_C(3235), UINT16_C(3227), UINT16_C(3219), 
UINT16_C(3211), UINT16_C(3204), UINT16_C(3196), UINT16_C(3189), UINT16_C(3181), UINT16_C(3174), UINT16_C(3166), UINT16_C(3159), 
UINT16_C(3152), UINT16_C(3145), UINT16_C(3138), UINT16_C(3131), UINT16_C(3124), UINT16_C(3117), UINT16_C(3110), UINT16_C(3103), 
UINT16_C(3096), UINT16_C(3090), UINT16_C(3083), UINT16_C(3076), UINT16_C(3070), UINT16_C(3063), UINT16_C(3057), UINT16_C(3050), 
UINT16_C(3044), UINT16_C(3037), UINT16_C(3031), UINT16_C(3025), UINT16_C(3018), UINT16_C(3012), UINT16_C(3006), UINT16_C(3000), 
UINT16_C(2994), UINT16_C(2988), UINT16_C(2982), UINT16_C(2976), UINT16_C(2970), UINT16_C(2964), UINT16_C(2958), UINT16_C(2952), 
UINT16_C(2947), UINT16_C(2941), UINT16_C(2935), UINT16_C(2929), UINT16_C(2924), UINT16_C(2918), UINT16_C(2913), UINT16_C(2907), 
UINT16_C(2901), UINT16_C(2896), UINT16_C(2891), UINT16_C(2885), UINT16_C(2880), UINT16_C(2874), UINT16_C(2869), UINT16_C(2864), 
UINT16_C(2858), UINT16_C(2853), UINT16_C(2848), UINT16_C(2843), UINT16_C(2838), UINT16_C(2832), UINT16_C(2827), UINT16_C(2822), 
UINT16_C(2817), UINT16_C(2812), UINT16_C(2807), UINT16_C(2802), UINT16_C(2797), UINT16_C(2792), UINT16_C(2787), UINT16_C(2782), 
UINT16_C(2778), UINT16_C(2773), UINT16_C(2768), UINT16_C(2763), UINT16_C(2758), UINT16_C(2754), UINT16_C(2749), UINT16_C(2744), 
UINT16_C(2740), UINT16_C(2735), UINT16_C(2730), UINT16_C(2726), UINT16_C(2721), UINT16_C(2716), UINT16_C(2712), UINT16_C(2707), 
UINT16_C(2703), UINT16_C(2698), UINT16_C(2694), UINT16_C(2689), UINT16_C(2685), UINT16_C(2681), UINT16_C(2676), UINT16_C(2672), 
UINT16_C(2668), UINT16_C(2663), UINT16_C(2659), UINT16_C(2655), UINT16_C(2650), UINT16_C(2646), UINT16_C(2642), UINT16_C(2638), 
UINT16_C(2633), UINT16_C(2629), UINT16_C(2625), UINT16_C(2621), UINT16_C(2617), UINT16_C(2613), UINT16_C(2608), UINT16_C(2604), 
UINT16_C(2600), UINT16_C(2596), UINT16_C(2592), UINT16_C(2588), UINT16_C(2584), UINT16_C(2580), UINT16_C(2576), UINT16_C(2572), 
UINT16_C(2568), UINT16_C(2564), UINT16_C(2560), UINT16_C(2556), UINT16_C(2553), UINT16_C(2549), UINT16_C(2545), UINT16_C(2541), 
UINT16_C(2537), UINT16_C(2533), UINT16_C(2529), UINT16_C(2526), UINT16_C(2522), UINT16_C(2518), UINT16_C(2514), UINT16_C(2511), 
UINT16_C(2507), UINT16_C(2503), UINT16_C(2499), UINT16_C(2496), UINT16_C(2492), UINT16_C(2488), UINT16_C(2485), UINT16_C(2481), 
UINT16_C(2477), UINT16_C(2474), UINT16_C(2470), UINT16_C(2467), UINT16_C(2463), UINT16_C(2459), UINT16_C(2456), UINT16_C(2452), 
UINT16_C(2449), UINT16_C(2445), UINT16_C(2442), UINT16_C(2438), UINT16_C(2435), UINT16_C(2431), UINT16_C(2428), UINT16_C(2424), 
UINT16_C(2421), UINT16_C(2417), UINT16_C(2414), UINT16_C(2410), UINT16_C(2407), UINT16_C(2404), UINT16_C(2400), UINT16_C(2397), 
UINT16_C(2393), UINT16_C(2390), UINT16_C(2387), UINT16_C(2383), UINT16_C(2380), UINT16_C(2377), UINT16_C(2373), UINT16_C(2370), 
UINT16_C(2367), UINT16_C(2363), UINT16_C(2360), UINT16_C(2357), UINT16_C(2354), UINT16_C(2350), UINT16_C(2347), UINT16_C(2344), 
UINT16_C(2341), UINT16_C(2337), UINT16_C(2334), UINT16_C(2331), UINT16_C(2328), UINT16_C(2325), UINT16_C(2321), UINT16_C(2318), 
UINT16_C(2315), UINT16_C(2312), UINT16_C(2309), UINT16_C(2306), UINT16_C(2303), UINT16_C(2299), UINT16_C(2296), UINT16_C(2293), 
UINT16_C(2290), UINT16_C(2287), UINT16_C(2284), UINT16_C(2281), UINT16_C(2278), UINT16_C(2275), UINT16_C(2272), UINT16_C(2269), 
UINT16_C(2266), UINT16_C(2263), UINT16_C(2260), UINT16_C(2257), UINT16_C(2253), UINT16_C(2250), UINT16_C(2247), UINT16_C(2244), 
UINT16_C(2242), UINT16_C(2239), UINT16_C(2236), UINT16_C(2233), UINT16_C(2230), UINT16_C(2227), UINT16_C(2224), UINT16_C(2221), 
UINT16_C(2218), UINT16_C(2215), UINT16_C(2212), UINT16_C(2209), UINT16_C(2206), UINT16_C(2203), UINT16_C(2200), UINT16_C(2197), 
UINT16_C(2195), UINT16_C(2192), UINT16_C(2189), UINT16_C(2186), UINT16_C(2183), UINT16_C(2180), UINT16_C(2177), UINT16_C(2175), 
UINT16_C(2172), UINT16_C(2169), UINT16_C(2166), UINT16_C(2163), UINT16_C(2160), UINT16_C(2158), UINT16_C(2155), UINT16_C(2152), 
UINT16_C(2149), UINT16_C(2146), UINT16_C(2144), UINT16_C(2141), UINT16_C(2138), UINT16_C(2135), UINT16_C(2133), UINT16_C(2130), 
UINT16_C(2127), UINT16_C(2124), UINT16_C(2122), UINT16_C(2119), UINT16_C(2116), UINT16_C(2113), UINT16_C(2111), UINT16_C(2108), 
UINT16_C(2105), UINT16_C(2102), UINT16_C(2100), UINT16_C(2097), UINT16_C(2094), UINT16_C(2092), UINT16_C(2089), UINT16_C(2086), 
UINT16_C(2084), UINT16_C(2081), UINT16_C(2078), UINT16_C(2076), UINT16_C(2073), UINT16_C(2070), UINT16_C(2068), UINT16_C(2065), 
UINT16_C(2062), UINT16_C(2060), UINT16_C(2057), UINT16_C(2054), UINT16_C(2052), UINT16_C(2049), UINT16_C(2047), UINT16_C(2044), 
UINT16_C(2041), UINT16_C(2039), UINT16_C(2036), UINT16_C(2034), UINT16_C(2031), UINT16_C(2028), UINT16_C(2026), UINT16_C(2023), 
UINT16_C(2021), UINT16_C(2018), UINT16_C(2015), UINT16_C(2013), UINT16_C(2010), UINT16_C(2008), UINT16_C(2005), UINT16_C(2003), 
UINT16_C(2000), UINT16_C(1997), UINT16_C(1995), UINT16_C(1992), UINT16_C(1990), UINT16_C(1987), UINT16_C(1985), UINT16_C(1982), 
UINT16_C(1980), UINT16_C(1977), UINT16_C(1975), UINT16_C(1972), UINT16_C(1970), UINT16_C(1967), UINT16_C(1965), UINT16_C(1962), 
UINT16_C(1960), UINT16_C(1957), UINT16_C(1955), UINT16_C(1952), UINT16_C(1950), UINT16_C(1947), UINT16_C(1945), UINT16_C(1942), 
UINT16_C(1940), UINT16_C(1937), UINT16_C(1935), UINT16_C(1932), UINT16_C(1930), UINT16_C(1927), UINT16_C(1925), UINT16_C(1922), 
UINT16_C(1920), UINT16_C(1918), UINT16_C(1915), UINT16_C(1913), UINT16_C(1910), UINT16_C(1908), UINT16_C(1905), UINT16_C(1903), 
UINT16_C(1900), UINT16_C(1898), UINT16_C(1896), UINT16_C(1893), UINT16_C(1891), UINT16_C(1888), UINT16_C(1886), UINT16_C(1883), 
UINT16_C(1881), UINT16_C(1879), UINT16_C(1876), UINT16_C(1874), UINT16_C(1871), UINT16_C(1869), UINT16_C(1867), UINT16_C(1864), 
UINT16_C(1862), UINT16_C(1859), UINT16_C(1857), UINT16_C(1855), UINT16_C(1852), UINT16_C(1850), UINT16_C(1847), UINT16_C(1845), 
UINT16_C(1843), UINT16_C(1840), UINT16_C(1838), UINT16_C(1836), UINT16_C(1833), UINT16_C(1831), UINT16_C(1828), UINT16_C(1826), 
UINT16_C(1824), UINT16_C(1821), UINT16_C(1819), UINT16_C(1817), UINT16_C(1814), UINT16_C(1812), UINT16_C(1810), UINT16_C(1807), 
UINT16_C(1805), UINT16_C(1803), UINT16_C(1800), UINT16_C(1798), UINT16_C(1795), UINT16_C(1793), UINT16_C(1791), UINT16_C(1788), 
UINT16_C(1786), UINT16_C(1784), UINT16_C(1781), UINT16_C(1779), UINT16_C(1777), UINT16_C(1774), UINT16_C(1772), UINT16_C(1770), 
UINT16_C(1767), UINT16_C(1765), UINT16_C(1763), UINT16_C(1760), UINT16_C(1758), UINT16_C(1756), UINT16_C(1753), UINT16_C(1751), 
UINT16_C(1749), UINT16_C(1747), UINT16_C(1744), UINT16_C(1742), UINT16_C(1740), UINT16_C(1737), UINT16_C(1735), UINT16_C(1733), 
UINT16_C(1730), UINT16_C(1728), UINT16_C(1726), UINT16_C(1723), UINT16_C(1721), UINT16_C(1719), UINT16_C(1716), UINT16_C(1714), 
UINT16_C(1712), UINT16_C(1710), UINT16_C(1707), UINT16_C(1705), UINT16_C(1703), UINT16_C(1700), UINT16_C(1698), UINT16_C(1696), 
UINT16_C(1693), UINT16_C(1691), UINT16_C(1689), UINT16_C(1687), UINT16_C(1684), UINT16_C(1682), UINT16_C(1680), UINT16_C(1677), 
UINT16_C(1675), UINT16_C(1673), UINT16_C(1671), UINT16_C(1668), UINT16_C(1666), UINT16_C(1664), UINT16_C(1661), UINT16_C(1659), 
UINT16_C(1657), UINT16_C(1655), UINT16_C(1652), UINT16_C(1650), UINT16_C(1648), UINT16_C(1645), UINT16_C(1643), UINT16_C(1641), 
UINT16_C(1639), UINT16_C(1636), UINT16_C(1634), UINT16_C(1632), UINT16_C(1629), UINT16_C(1627), UINT16_C(1625), UINT16_C(1623), 
UINT16_C(1620), UINT16_C(1618), UINT16_C(1616), UINT16_C(1613), UINT16_C(1611), UINT16_C(1609), UINT16_C(1607), UINT16_C(1604), 
UINT16_C(1602), UINT16_C(1600), UINT16_C(1597), UINT16_C(1595), UINT16_C(1593), UINT16_C(1591), UINT16_C(1588), UINT16_C(1586), 
UINT16_C(1584), UINT16_C(1582), UINT16_C(1579), UINT16_C(1577), UINT16_C(1575), UINT16_C(1572), UINT16_C(1570), UINT16_C(1568), 
UINT16_C(1566), UINT16_C(1563), UINT16_C(1561), UINT16_C(1559), UINT16_C(1556), UINT16_C(1554), UINT16_C(1552), UINT16_C(1550), 
UINT16_C(1547), UINT16_C(1545), UINT16_C(1543), UINT16_C(1540), UINT16_C(1538), UINT16_C(1536), UINT16_C(1534), UINT16_C(1531), 
UINT16_C(1529), UINT16_C(1527), UINT16_C(1524), UINT16_C(1522), UINT16_C(1520), UINT16_C(1517), UINT16_C(1515), UINT16_C(1513), 
UINT16_C(1511), UINT16_C(1508), UINT16_C(1506), UINT16_C(1504), UINT16_C(1501), UINT16_C(1499), UINT16_C(1497), UINT16_C(1494), 
UINT16_C(1492), UINT16_C(1490), UINT16_C(1488), UINT16_C(1485), UINT16_C(1483), UINT16_C(1481), UINT16_C(1478), UINT16_C(1476), 
UINT16_C(1474), UINT16_C(1471), UINT16_C(1469), UINT16_C(1467), UINT16_C(1464), UINT16_C(1462), UINT16_C(1460), UINT16_C(1457), 
UINT16_C(1455), UINT16_C(1453), UINT16_C(1451), UINT16_C(1448), UINT16_C(1446), UINT16_C(1444), UINT16_C(1441), UINT16_C(1439), 
UINT16_C(1437), UINT16_C(1434), UINT16_C(1432), UINT16_C(1430), UINT16_C(1427), UINT16_C(1425), UINT16_C(1423), UINT16_C(1420), 
UINT16_C(1418), UINT16_C(1415), UINT16_C(1413), UINT16_C(1411), UINT16_C(1408), UINT16_C(1406), UINT16_C(1404), UINT16_C(1401), 
UINT16_C(1399), UINT16_C(1397), UINT16_C(1394), UINT16_C(1392), UINT16_C(1390), UINT16_C(1387), UINT16_C(1385), UINT16_C(1382), 
UINT16_C(1380), UINT16_C(1378), UINT16_C(1375), UINT16_C(1373), UINT16_C(1371), UINT16_C(1368), UINT16_C(1366), UINT16_C(1363), 
UINT16_C(1361), UINT16_C(1359), UINT16_C(1356), UINT16_C(1354), UINT16_C(1351), UINT16_C(1349), UINT16_C(1347), UINT16_C(1344), 
UINT16_C(1342), UINT16_C(1339), UINT16_C(1337), UINT16_C(1334), UINT16_C(1332), UINT16_C(1330), UINT16_C(1327), UINT16_C(1325), 
UINT16_C(1322), UINT16_C(1320), UINT16_C(1317), UINT16_C(1315), UINT16_C(1313), UINT16_C(1310), UINT16_C(1308), UINT16_C(1305), 
UINT16_C(1303), UINT16_C(1300), UINT16_C(1298), UINT16_C(1295), UINT16_C(1293), UINT16_C(1290), UINT16_C(1288), UINT16_C(1285), 
UINT16_C(1283), UINT16_C(1280), UINT16_C(1278), UINT16_C(1276), UINT16_C(1273), UINT16_C(1271), UINT16_C(1268), UINT16_C(1265), 
UINT16_C(1263), UINT16_C(1260), UINT16_C(1258), UINT16_C(1255), UINT16_C(1253), UINT16_C(1250), UINT16_C(1248), UINT16_C(1245), 
UINT16_C(1243), UINT16_C(1240), UINT16_C(1238), UINT16_C(1235), UINT16_C(1233), UINT16_C(1230), UINT16_C(1227), UINT16_C(1225), 
UINT16_C(1222), UINT16_C(1220), UINT16_C(1217), UINT16_C(1215), UINT16_C(1212), UINT16_C(1209), UINT16_C(1207), UINT16_C(1204), 
UINT16_C(1201), UINT16_C(1199), UINT16_C(1196), UINT16_C(1194), UINT16_C(1191), UINT16_C(1188), UINT16_C(1186), UINT16_C(1183), 
UINT16_C(1180), UINT16_C(1178), UINT16_C(1175), UINT16_C(1172), UINT16_C(1170), UINT16_C(1167), UINT16_C(1164), UINT16_C(1162), 
UINT16_C(1159), UINT16_C(1156), UINT16_C(1154), UINT16_C(1151), UINT16_C(1148), UINT16_C(1145), UINT16_C(1143), UINT16_C(1140), 
UINT16_C(1137), UINT16_C(1134), UINT16_C(1132), UINT16_C(1129), UINT16_C(1126), UINT16_C(1123), UINT16_C(1121), UINT16_C(1118), 
UINT16_C(1115), UINT16_C(1112), UINT16_C(1109), UINT16_C(1107), UINT16_C(1104), UINT16_C(1101), UINT16_C(1098), UINT16_C(1095), 
UINT16_C(1092), UINT16_C(1090), UINT16_C(1087), UINT16_C(1084), UINT16_C(1081), UINT16_C(1078), UINT16_C(1075), UINT16_C(1072), 
UINT16_C(1069), UINT16_C(1067), UINT16_C(1064), UINT16_C(1061), UINT16_C(1058), UINT16_C(1055), UINT16_C(1052), UINT16_C(1049), 
UINT16_C(1046), UINT16_C(1043), UINT16_C(1040), UINT16_C(1037), UINT16_C(1034), UINT16_C(1031), UINT16_C(1028), UINT16_C(1025), 
UINT16_C(1022), UINT16_C(1019), UINT16_C(1016), UINT16_C(1013), UINT16_C(1009), UINT16_C(1006), UINT16_C(1003), UINT16_C(1000), 
UINT16_C(997), UINT16_C(994), UINT16_C(991), UINT16_C(988), UINT16_C(984), UINT16_C(981), UINT16_C(978), UINT16_C(975), 
UINT16_C(972), UINT16_C(968), UINT16_C(965), UINT16_C(962), UINT16_C(959), UINT16_C(955), UINT16_C(952), UINT16_C(949), 
UINT16_C(945), UINT16_C(942), UINT16_C(939), UINT16_C(935), UINT16_C(932), UINT16_C(929), UINT16_C(925), UINT16_C(922), 
UINT16_C(918), UINT16_C(915), UINT16_C(911), UINT16_C(908), UINT16_C(905), UINT16_C(901), UINT16_C(898), UINT16_C(894), 
UINT16_C(890), UINT16_C(887), UINT16_C(883), UINT16_C(880), UINT16_C(876), UINT16_C(873), UINT16_C(869), UINT16_C(865), 
UINT16_C(862), UINT16_C(858), UINT16_C(854), UINT16_C(850), UINT16_C(847), UINT16_C(843), UINT16_C(839), UINT16_C(835), 
UINT16_C(831), UINT16_C(828), UINT16_C(824), UINT16_C(820), UINT16_C(816), UINT16_C(812), UINT16_C(808), UINT16_C(804), 
UINT16_C(800), UINT16_C(796), UINT16_C(792), UINT16_C(788), UINT16_C(784), UINT16_C(780), UINT16_C(776), UINT16_C(771), 
UINT16_C(767), UINT16_C(763), UINT16_C(759), UINT16_C(754), UINT16_C(750), UINT16_C(746), UINT16_C(741), UINT16_C(737), 
UINT16_C(733), UINT16_C(728), UINT16_C(724), UINT16_C(719), UINT16_C(715), UINT16_C(710), UINT16_C(705), UINT16_C(701), 
UINT16_C(696), UINT16_C(691), UINT16_C(687), UINT16_C(682), UINT16_C(677), UINT16_C(672), UINT16_C(667), UINT16_C(662), 
UINT16_C(657), UINT16_C(652), UINT16_C(647), UINT16_C(642), UINT16_C(637), UINT16_C(632), UINT16_C(626), UINT16_C(621), 
UINT16_C(616), UINT16_C(610), UINT16_C(605), UINT16_C(599), UINT16_C(594), UINT16_C(588), UINT16_C(582), UINT16_C(577), 
UINT16_C(571), UINT16_C(565), UINT16_C(559), UINT16_C(553), UINT16_C(547), UINT16_C(541), UINT16_C(535), UINT16_C(528), 
UINT16_C(522), UINT16_C(516), UINT16_C(509), UINT16_C(503), UINT16_C(496), UINT16_C(489), UINT16_C(482), UINT16_C(475), 
UINT16_C(468), UINT16_C(461), UINT16_C(454), UINT16_C(446), UINT16_C(439), UINT16_C(431), UINT16_C(424), UINT16_C(416), 
UINT16_C(408), UINT16_C(400), UINT16_C(392), UINT16_C(383), UINT16_C(375), UINT16_C(366), UINT16_C(357), UINT16_C(348), 
UINT16_C(339), UINT16_C(329), UINT16_C(320), 
};

#include <aprinter/EndNamespace.h>

#endif 
