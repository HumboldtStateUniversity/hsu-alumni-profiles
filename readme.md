# HSU Alumni Profiles
Drupal 7: This feature adds an alumni profile content type, feeds importer, and several views for displaying HSU Alumni Profiles on your OpenHSU website.

Profile submissions can be made here https://www.humboldt.edu/new-alumni-profile and will be imported to each department website based on submission major. 

This feature should be used with the OpenHSU platform only.

##Install

## Modules needed
    hsu_alumni_profiles
    feeds (https://www.drupal.org/project/feeds) version = "7.x-2.0-beta4"
    feeds_ex (https://www.drupal.org/project/feeds_ex) version = "7.x-1.0-beta2"
    Job_scheduler (https://www.drupal.org/project/job_scheduler) version = "7.x-2.0-alpha3"

## Libraries
    Jsonpath (https://registry.npmjs.org/JSONPath/-/JSONPath-0.8.3.tgz) 
Place this file in sites/all/libraries/jsonpath/jsonpath.php

*Enable the module*
 
You will get the error - "Missing Feeds plugin FeedsExJsonPath."   This is a known bug and will resolve when you clear the cache from the drupal UI.

To add the feeds import url go to <yourwebsite.humboldt.edu>/import 
You will need to request your departments import url by emailing marcom@humboldt.edu.

There are 5 usable views that come packaged with the feature.
View this <a href="https://docs.google.com/document/d/1V26Xv7x1i7Lob9ftVfr3O4FBqHi4POBCJCCDkrHCVOc/edit?usp=sharing">Google Doc</a> for more info.
