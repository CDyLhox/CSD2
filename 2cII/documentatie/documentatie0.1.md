# the elecflute - documentation
![](https://cagedotlog.com/backend/elecflute/assets/elecflutev0.8.webp)
## [DESIGN]
the concept design document can be found at 2cII/design.md

## [DIAGRAMS]
the system diagrams can be found at 2cII/documentatie/diagrams.md

## [process description]
##### i will describe the design process and mapping below!

so i started this project with and idea in my head; a sound.. this type of sound has been brewing in my head for the past year and i have loved this type of sound since i was a little boy.

Now im a big boy i wanted to make this sound and be able to use it! so i told my teacher Ciska about the sound i wanted to make. she told me to prototype it and so prototyping is what i went to do. 

i prototyped a timestretcher -> reverb -> filter in puredata (plugdata technically. (i used the ELSE library))
the prototype of this can be found at https://cagedotlog.com/backend/elecflute/index.html

[clickable link](https://cagedotlog.com/backend/elecflute/index.html)


then i finetuned the  stretch amounts to my liking and filtering so it would sound warm and not too digital. this all turned out to be completely useless!

the timestretching sound i was looking for was based on something called a phase vocoder. which is itself based on a IFFT system. 
for this project FFT's are <span style="color:red"> ILLEGAL </span> so sadly this was not an option.

im still super glad i made a prototype though, cause it gave me room to experiment and be sure of the sound i wanted before i started working in JUCE

i ended up using a reverb with freeze instead which was not completely the desired sound but still got the job done

###### the controller
some people will look at this and see janky, i look at this and see beauty.
![](https://cagedotlog.com/backend/elecflute/assets/elecflutev1.webp)

if you compare this to my original design you can see theres some differences
![](https://cagedotlog.com/backend/elecflute/design/parts%20of%20elecflute.webp)
lets adress the elephant in the room: the can!
the can is something i came up with while brainstorming about how i *can* safely transport the electronics when the flute is a modular instrument. The flute being modular created the problem that i cant just glue my parts onto the flute cause then it wouldnt fit together correctly anymore. 

i also considered attaching the slider connectors to clip on cables so i could connect and disconnect the slider on the fly, but this still left me with the problem of safely transporting the flute parts without them getting damaged. after looking around my room for a while i noticed this can of mango juice 
![](https://imgs.search.brave.com/CvAbB-nXvDP1mZLQByxTl84ruSDNDN_4BeA8hFBgjJI/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly9jZG4u/d2Vic2hvcGFwcC5j/b20vc2hvcHMvMjI1/NTAzL2ZpbGVzLzE0/MjU0NTU2Ni81MDB4/NTAweDIvaW1hZ2Uu/anBn)

so i drunk it like that! it tasted great too, not so synthetic, though it says its not from concentrate.. whatever that means. 

the can is very sturdy, but smooth on the inside and in my opinion looks very cute. its also exactly the right size to fit all of my electronics and still fit the flute along side it.
i duct taped the inside so i wouldn't fry the chips once i put them inside, then i borrowed some copper rods from my friend [Midas Munstermann](https://midasdepidas.com/). 

with these copper rods i made some coils which would fit perfectly around the flute, and could then apply pressure on the inside of the can so the can wouldnt move around too much.
![](https://cagedotlog.com/backend/elecflute/assets/crossection.webp)

and the thurough reader will also notice that the slider moved further right than i anticipated in the design plan. this is because the natural position for a flute player's thumb is where i put the slider later on. though in my playtest with an actual real life flute player, they didnt immediately get this so i will need to do some more interaction design.

and one last thing, the flute was supposed to have a microphone but eventually ended up without. this is because while building, and having the deadline closing in on me. i had some trouble with the dac output of the flute, and instead of focussing all my energy on this, i decided to rewrite the functionality of the script to send osc information over tailscale instead.

this works great! and i might keep it this way to make the flute more portable, i will still want to try using a microphone and see if i can send audio over rtp so i can make the flute completely wireless.

## [selected learning objectives and reflection]

[selectd]
prompt: De CSD’er kan het beoogde ontwerp afstellen op de eigen capaciteit, zowel wbt het afbakenen ter voorkoming van overbelasting als opschalen ter voorkoming van onderbelasting.

reaction: het nice gene aan dit in mijn bewandelde boog is dat ik het heel letterlijk heb meegemaakt. Toen ik erachter kwam dat de microfoon niet ging werken ben ik niet uren gaan troubleshooten maar heb ik gekozen om dit deel achter me te laten en door te werken. hetzelfde geldt over de fft timestretcher loslaten. en mijn dsp blok halen wat me vorig jaar niet lukte naast het csd hoofdvak


prompt: De CSD’er kan stapsgewijs aan afgebakende onderdelen van het ontwerp, systeem en implementatie werken.

reaction: ik heb gewerkt van een prototype, naar mijn eerste geluidseffect (delay), dan naar een reverb, en een filter erover heen, en daarna heb ik de hardware in elkaar gezet. tijdens het schrijven van de geluidseffecten heb ik wel gespeeld met verschillende slider locaties op de fluit. zodat het systeem in principe al af was tegen de tijd dat ik begonnen was met de hardware daadwerkelijk maken.

[non selected]
you think of some here

#### [overal reflection]

im happy with how this turned out, mainly because i learned a few new techniques i hadnt learned last year. this year, while combining dsp and csd (as the program intended), i actually understood the digital signal processing i was doing. it was no longer just abstract math which is the biggest "mind blown" moment for me. It inspires me to want to make more sound effects, and i remembered that i love cpp as a language. There were a few points where i could still improve my work ethic, the day before the deadline i still had to work till 3 in the morning just to make the deadline which is preferrably avoided in the future. i just need to get a flipping tattoo on the inside of my eyelid reminding me of these types of things i need to do because damn if i ever get a night off i forget that theres usually more stuff that needs doing.

a more technical improvement i can think of now is that the slider needs te be more flush with the instrument to make it more playable. also if i can get the machine battery powered that'd be great so i can send osc data over tailscale. 
in the code an improvement would be getting the reverb to sound better :)               how do you wish to do this?          more allpasses. more delays. better delay values.

the best part of the entire process was not worrying myself to death about what would happen if i didnt make the deadline. i was from the beginning pretty confident in my ability to finish it in time and even if i wouldnt i didnt think the entire world would end which is to me a sign of personal growth. 

some takeaways i realised this semester about what went wrong last year and how to do better in the future
* last year (it feels like to me) i started with one idea, and the idea kept evolving as the semester continued on. where it went wrong is that i was too scared to communicate about the idea changing into something new because i thought this wasnt allowed, or that people wouldnt understand the idea, or something along those lines. these are all just ways my brain wants to trick me into being small, which is a funny little thing to do. it doesnt matter though, i just need to actively choose to show who i am and why i want these things i want. so for the next semester, be yourself boo.
* and also. its great not worrying yourself to a skidmark, but dont do the oppisite either. everything is always somewhere in the middle. dont forget you care about the project youre making. 

no more thoughts 
