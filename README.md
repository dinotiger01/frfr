# mtg tool
![Screenshot_20260920_185849.png](screenshots/Screenshot_20260920_185849.png)
***
demo: https://youtu.be/mxpGiXnvjhE<br>
i made this simple tool to make bulk custom mtg cards<br>
this is my first time i have ever used qml and c++ i was quite the learning experience
***
## how to use
* add a deck list
  * paist a deck list into the text box in the top right
  * a deck list needs a number and a name of the card 
  * example is below
* click find
  * this will look through all the cards in the database
  * after its done it should remove evreyting in the text box
* click load
  * this will load all the cards that it found during the previuse serch then load them on the side
* custimze your pictures
  * select a card
    * click any of the cards on the left side
  * add a picture
    * drag and drop a picture into the green drop area
    * it can be a file or it can be a link to a picture off the web
    * it only suports .png and .jpg
  * edit picture
    * at the start it will be a weird aspect ratio you need to drag it around a bit to fix that
    * you can use the blue square to scale the img
    * you can drag the picture around
  * save
    * you need to save before clicking off the card then it will save 
  * skip 
    * some cards wont work becaouise the picture has a different aspect ratio
* finded mised
  * so you can click load_mis
  * this will add all skiped cards and cards in the deck list the were in an invalid format
  * this isnet requared but if you skip a card you can still make it in like photoshop then import it in to the batch export
  * import
    * to import somthing into the export you need to drag a picture in to the import section
    * then you give the card a name
    * then use the + and - buttons to chose how many of those cards you want
    * then click the button to add it, it wil then add the card to a list underneeth so you can see what imports you have done
* export
  * once you are done with all the cards you can click export
  * there is a bug so you NEED to full screen becouse the buttons are too far down so you cant see them at the normal aspect ratio
  * then you click load first it will pull up 9 cards from the back of the list
  * then click export it will save those 9 cards as a picture in the output folder
  * you click load after that it will pull up the next 9 then you export 
  * repete till all are done then you can print those images then cut them to have all your cards
# deck list example
***
[COMMANDER]<br>
1 Muerra, Trash Tactician<br>
<br>
[COST 1]<br>
1 Celestial Reunion<br>
1 Sol Ring<br>
1 Vandalblast<br>
<br>
[COST 2]<br>
1 Bakersbane Duo<br>
1 Bark-Knuckle Boxer<br>
1 Brazen Collector<br>
1 Goblin Anarchomancer<br>
1 Heroic Intervention<br>
1 Hoarder's Overflow<br>
1 Keen-Eyed Curator<br>
1 Lightning Greaves<br>
1 Masked Vandal<br>
1 Metallic Mimic<br>
1 Peerless Recycling<br>
1 Raccoon Rallier<br>
1 Steely Resolve<br>
1 Take Out the Trash<br>
1 Trailtracker Scout<br>
1 Wandertale Mentor<br>
<br>
[COST 3]<br>
1 Adaptive Automaton<br>
1 Barkform Harvester<br>
1 Beast Within<br>
1 Bloodline Pretender<br>
1 Brambleguard Veteran<br>
1 Byway Barterer<br>
1 Chomping Changeling<br>
1 Coati Scavenger<br>
1 For the Ancestors<br>
1 Herald's Horn<br>
1 Patchwork Banner<br>
1 Prosperous Bandit<br>
1 Realmwalker<br>
1 Roughshod Duo<br>
1 Scrapshooter<br>
1 Sylvan Scavenging<br>
1 Taurean Mauler<br>
1 Valley Flamecaller<br>
<br>
[COST 4]<br>
1 Big Score<br>
1 Chameleon Colossus<br>
1 Decimate<br>
1 Gathering Stone<br>
1 Maskwood Nexus<br>
1 Molten Echoes<br>
1 Roaming Throne<br>
1 Roar of the Crowd<br>
1 Rust-Shield Rampager<br>
1 Scrappy Bruiser<br>
1 Teapot Slinger<br>
<br>
[COST 5]<br>
1 Banner of Kinship<br>
1 Collective Inferno<br>
1 Escape to the Wilds<br>
1 Junkblade Bruiser<br>
1 Return of the Wildspeaker<br>
1 Vanquisher's Banner<br>
<br>
[COST 6]<br>
1 Argivian Avenger<br>
<br>
[COST 7+]<br>
1 Blasphemous Act<br>
<br>
[LANDS]<br>
1 Cavern of Souls<br>
1 Cinder Glade<br>
1 Command Tower<br>
1 Copperline Gorge<br>
15 Forest<br>
1 Game Trail<br>
1 Kessig Wolf Run<br>
15 Mountain<br>
1 Oakhollow Village<br>
1 Path of Ancestry<br>
1 Rockface Village<br>
1 Rockfall Vale<br>
1 Rootbound Crag<br>
1 Stomping Ground<br>
1 Three Tree City<br>
<br>
<br>
// TOKENS<br>
Copy (C)<br>
Food (C)<br>
Treasure (C)<br>
3/3 - Beast (G)<br>
3/3 - Raccoon (G)<br>
1/1 - Rust-Shield Rampager (G)<br>
1/1 - Prosperous Bandit (R)<br>
2/2 - Shapeshifter (U)<br>