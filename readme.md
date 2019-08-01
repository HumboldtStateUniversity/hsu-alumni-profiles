# HSU Alumni Profiles
This Drupal 7 feature will allow you to add Alumni Profiles to your OpenHSU website. It includes a new content type, feeds importer, and several views for displaying the profiles using panelizer.<br><br>
Notes:
<br>•&nbsp; Profile submissions can be made to https://www.humboldt.edu/new-alumni-profile and will be imported to each department website based on major. 
<br>•&nbsp; This feature should be used with the OpenHSU platform only.

## Requirements

### Modules 
In addition to OpenHSU modules:<br>
hsu_alumni_profiles (this repo)<br>
[feeds (7.x-2.0-beta4)](https://www.drupal.org/project/feeds)<br> 
[feeds_ex (7.x-1.0-beta)](https://www.drupal.org/project/feeds_ex)<br>
[Job_scheduler (7.x-2.0-alpha3)](https://www.drupal.org/project/job_scheduler) <br>

### Libraries
[Jsonpath](https://registry.npmjs.org/JSONPath/-/JSONPath-0.8.3.tgz) <br>
Place this file in sites/all/libraries/jsonpath/jsonpath.php
    
## Instructions
1. Download this [Drush make file](https://gist.github.com/jeniferfitch/b555e01d15cb7518af1c4a552a7d8649)
2. Place hsu_alumni_profiles.make.yml in the root of your the sites repo
3. Run `drush make --no-core hsu_alumni_profiles.make.yml` This puts the correct modules and jsonpath libraries in the right place. 
4. Enable the module 
6. You will get the error - "Missing Feeds plugin FeedsExJsonPath."   This is a known bug and will resolve when you clear the cache from the drupal UI.
5. Add the feeds import url<br>
   •&nbsp; Request your departments import url by emailing webadmin@humboldt.edu<br>
   •&nbsp; go to http://< yourwebsite >/import and add the feeds import url and import<br>
6. Add one of the 5 display panes to your site using panelizer > customize this page > add content > view panes. View this <a href="https://docs.google.com/document/d/1V26Xv7x1i7Lob9ftVfr3O4FBqHi4POBCJCCDkrHCVOc/edit?usp=sharing">Google Doc</a> for a visual representation of the views.