# [🗲  Join the Robzyl Dev Telegram](https://t.me/k5robby69)
## [🗲 Youtube Channel](https://www.youtube.com/@robby_69400)
### 🙏 Many thanks to Robzyl Team : Zylka, Kolyan, Iggy, Toni, Yves and Francois

This software is a fork of Armel F4HWN firmware with code from NTOIVOLA, EGZUMER and DUAL TACHYON.
Refer to this manual for global instructions,[🗲 F4HWN Manual](https://github.com/armel/uv-k1-k5v3-firmware-custom/wiki)
Here we describe the spectrum and specific instructions for Robzyl:
# SEE HISTORY CHANGE HERE BELOW
# Robzyl K1 Firmware Documentation
**USB is deactivated by default**: press any key but PTT when switch ON to enable USB**

**CHIRP Driver included**: `Chirp_Robzyl_K1.py`  
This driver also allows 
* **customization of the 50 bands on channels 975 to 1024.**
Select start frequency  and offset as stop frequency, step and modulation

* **Scanlist Monitor setting**
Select up to 20ch to Monitor scanlist anywhere in the channels.
<img width="2573" height="612" alt="image" src="https://github.com/user-attachments/assets/65648e2e-808f-4594-b7ce-bb3b91204502" />

## Robzyl Spectrum

| Mode | Description |
|---------|-------------|
| **BAND** | 24 configurable bands |
| **SCAN-LIST** | 20 scan-lists based on your memory channels |
| **RANGE** | Spectrum within start/end frequency limits |
| **FREQUENCY** | Spectrum centered on the VFO frequency |

### Practical Use

**Launch Spectrum**: `F+5` from VFO mode.
Spectrum launch  can also be affected to a Side Key in menu.
<img width="512" height="320" alt="image" src="https://github.com/user-attachments/assets/e1b36840-c0e6-4747-ac08-284a64d65f9c" />

![Main View](https://github.com/user-attachments/assets/f28463e6-5542-4c1d-ace4-b2ab3a44c4ac)

* **Top line**: DSxx (Dynamic Squelch), Modulation, Listen BW, Step (or A+XXXX/AFC during listening).
* **Second line**: Current frequency and scan-list or band (depending on mode).
* **Bottom line**: Current span and dbm level or channel scan speed

**Key Mapping:**

| Key | Function |
|-----|----------|
| **1** | Skip receiving frequency |
| **2** | Simplified screen (scanner) |
| **3** | Select listening bandwidth |
| **4** | Selection menu (single/multiple SL or BD) |
| **5** | Access Settings (</> to navigate, 1/3 to change values) |
| **6** | Toggle BAND, SCAN-LIST, RANGE, FREQUENCY modes |
| **7** | Save main settings |
| **8** | Toggle BIG/CLASSIC/LAST RX/BENCH display |
| **9** | Select modulation |
| **0** | Access reception history |
| **M** | Enter Still Mode (monitoring and register access) |
| **PTT** | transmit to LAST RX/LAST VFO/NINJA, as selected in [5] |
| **SIDE KEY 1** | Toggle Normal -> FL (Freq Lock) -> M (Monitor) |
| **SIDE KEY 2** | Blacklist last recived frequency |
| ***/F** | Adjust Dynamic Squelch (Uxx) |
| **< >** | Navigate SL, bands, or frequency |

---

## Settings Menu

![Settings Menu](https://github.com/user-attachments/assets/be9c4ea0-72ca-4fc9-85d7-323c3553bb9f)

* **RSSI Delay**: RSSI capture time in ms.
* **SpectrumDelay**: Hang time after signal drops below squelch.
* **Max Listen Time**: Maximum listening time for a received signal.
* **Fstart/Fstop**: Set start/stop frequencies (RG mode).
* **Step**: Set frequency stepping.
* **ListenBW**: Set listening bandwidth.
* **Modulation**: FM/AM/USB.
* **RX_Backlight_ON**: Enable backlight during spectrum reception.
* **PowerSave**: adds sleep between scan cycles to reduced power consumption.
* **Noislvl_OFF**: Noise floor adjustment to avoid false triggers.
* **Popups**: Message display duration.
* **Record Trig**: Level to save history when Dynamic Squelch is OFF.
* **Key Unlocked**: Auto keypad lock.
* **GlitchMax**: Noise rejection level.
* **SoundBoostON**: Higher volume (risk of distortion).
* **Monitor SL**: activates the regular monitoring of channels identified as Monitor scanlist.
* **Clear History All**:   Erase EEPROM history.
* **Clear History N BL**:  Erase history but keep blacklisted frequencies.
* **Clear History BL**:    Erase blacklisted frequencies.

* **Reset Default**: Reset spectrum parameters and registers.

---

## Operating Modes

### 1. Simplified View
![Simplified View](https://github.com/user-attachments/assets/3594c6c6-728a-4ffc-88ac-5495ab352456)
Summary: Ambient Temp, RSSI level, Frequency, and Channel/Band name.

### 2. Still Mode (Monitoring)
![Still Mode](https://github.com/user-attachments/assets/a51c16cc-7d03-49ff-99f2-9cfc6ff8f52b)
Launched with **M** during active listening. Advanced users can modify registers here.
* **< >**: Change frequency by step.
* ***/F**: Change step size.

### 3. Frequency History
![Frequency History](https://github.com/user-attachments/assets/b0ca73b5-b64a-4b85-bcc2-ee6ffac59bb0)
Dynamic list of received signals. Navigate to listen (auto-engages Freq Lock).
* **SK1**: Toggle FL / Monitor.
* **< >**: Navigate history (FL mode).
* **2**: Save entry to first available memory slot.
* **5**: Scan history entries.
* **7**: Save history to EEPROM.

### 4. ScanLists (SL Mode)
![ScanList Selection](https://github.com/user-attachments/assets/722c1eeb-30ce-4433-9f66-1ccab36be85a)
* **Function**: Loads memories assigned to scanlists into the spectrum.
* **Menu [4]**: Select SLs with **^/v**. **[5]** for exclusive, **[4]** for multi-select.

### 5. Predefined Bands (BAND Mode)
![Band Selection](https://github.com/user-attachments/assets/75c924b3-139a-4d04-8fde-337045eba6d0)
* **Function**: Analyzes preset bands (PMR, CB, AERO, HAM, etc.).

---

## Chirp Configuration 
<img width="2614" height="814" alt="image" src="https://github.com/user-attachments/assets/b6bf2c7a-1aa1-4822-8ab1-a7f97d448930" />
Memory channels **975 to 1024** store custom band settings. For each, define:
* Start and End frequency (via offset).
* Band Name.
* Modulation & Frequency Step.



# HISTORY CHANGES
## V6.20 to V6.21
* Add count and code to history
* BL fix working in spectrum and history
* show RAM usage in BENCH menu
* fix close call didn't exit
