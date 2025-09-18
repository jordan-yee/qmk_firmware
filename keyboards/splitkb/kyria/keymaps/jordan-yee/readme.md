# How to flash my Kyria

Here are some notes on my experience with updating the QMK Firmware after
several years and updating my custom keymap. (09/17/2025)

> Left hand is the Elite C, and the right hand is the Pro Micro controller.

## The Process & Lessons Learned

- I cloned my forked version of the official QMK Firmware repo into WSL to modify
  the code/files in there.
  - I also installed the qmk cli tools there, but because you can't flash from
    WSL, that isn't particularly helpful unless you want to iterate on compiling.
- I also cloned the same in my user directory in Windows.
- I installed both the QMK Toolbox GUI flash application and the QMK MSYS CLI
  application on Windows.
  - I thought I might need the CLI application to flash the Pro Micro side
    because it wouldn't stay in bootloader mode for more than a few seconds
    when trying to use the QMK Toolbox. However, that seems to actually just
    be a thing with the contoller itself.
- On Windows, the QMK MSYS CLI installer added a profile to Windows Terminal.
- Open the Toolbox or Windows Terminal as admin to enable it to install
  drivers.
- I had to work through some issues after rebasing my custom branch onto the
  latest version of master after updating my fork in GitHub and pulling master.
  - Get the QMK dependencies and execute the health checks by running
    `qmk setup` in the qmk repo (but it seemed able to find the repo when
    running from home dir as well).
  - On Windows, `qmk setup` would run through several steps then hang on
    attempts to update submodules. These could be updated manually outside of
    the setup, then re-running the setup worked successfully.
- Running `qmk config user.config=splitkb/kyria/rev1` and the same with
  `user.keymap=jordan-yee` enables you to run `qmk compile` without the flags
  that specify the same.

1. Update the QMK fork.
2. Pull the latest master down locally.
3. Rebase the custom keymap branch onto master (I had split of a new, dated
   branch from the previous custom branch this time around).
4. Attempt to compile `qmk compile` (assuming you set the config values above).
   - Fix any errors. Errors I faces this time:
     - Some keycodes had been changed in the newer QMK version. To update,
         reference the default kyria/rev1 file or the keycodes on the website.
     - I added a layer, which exceeded the max layer count configured in my
       `config.h` file. I upped this from 8 to 16.
5. Once it compiles correctly, you get a `.hex` file in the repo's root dir.
6. Open QMK Toolbox (as admin).
   - From one of the drop down menus at the top install drivers, if you didn't
     already do so using the `qmk setup` command from the Windows CLI.
   - Open this `.hex` file in there.
   - I did not have to change the default value of the `MCU (AVR only)`
     dropdown, which was set to `ATmega32U4` for either half of the kb.
7. Flash the updated, compiled firmware.
   - Unplug both haves of the keyboard from each other and from the computer.
   - Plug in the main (Elite C/Left) half first. Wait a sec to let the system
     detect and install drivers for this.
   - Then press the flash/reset button on the side of the keyboard. The QMK
     Toolbox console shows a yellow `device connected` message after a delay.
   - Then click Flash to flash the firmware. After it shows messages about
     flashing being complete, you can disconnect that half of the kb.
   - Plug in the second (Pro Micro/Right) half and repeat.
     - This half shows up as `Caterina device connected...` after pressing the
       bootloader/reset button.
     - UPDATE: You may have to double-tap the reset button for this one. This
       time, my first attempt at auto-flashing with only pressing it once had
       errors, but the second time I double-tapped the reset and it worked.
     - This one automatically disconnects after only a few seconds, making it
       harder to flash--you just have to flash it while you can.
     - Checking/enabling `Auto-Flash` is probably the way to go here.
     - I also ran into errors when first figuring this out. I clicked the reset
       button, then as soon as the `connected` message appeared, I clicked the
       `Clear EEPROM` button. This took a few attempts to be successful.
     - Then Auto-Flashing the firmware also did work after a few attempts.
8. Once both halves have been successfully flashed, you can unplug everything,
   reconnect the keyboard halves, and replug it in. It should just work now.
