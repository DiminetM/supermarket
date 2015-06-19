@ECHO OFF
@ECHO Initializing Drush
@SET PATH=%PATH%;C:\ProgramData\Drush\
@SET PATH=%PATH%;C:\Tools\Drush\GnuWin32\bin
@SET PATH=%PATH%;C:\Tools\Drush\Php
@SET PATH=%PATH%;C:\Tools\Drush\cwRsync\bin
@ECHO Deleting old directories
rd modules\contrib /s /q
rd libraries /s /q
:: rd themes\contrib /s /q
@ECHO Starting build
drush -y make --working-copy --no-core --contrib-destination=. ipgroup-md.make
