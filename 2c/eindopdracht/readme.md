## THE EINDOPDRACHT 2c :: 17 mar 2025

for videos and information check out:
http://cagedotlog.com/backend/csdDemo/TS17mar.html

for vocals, a lower maxNumZeroCrossings is recommended.


feel better:
    beter wroden in vragen stellen 
    opdracht doorlezen met geduld en een plan voor mezelf bedenken (grootschalig probleem)
    beter geworden in loslaten 
    ideaalbeeld wel los laten in ruil voor het eindproduct
    heb wel meer confidence en minder gevoel van een tekort aan overzicht
    het is er wel nog


TODOS:

=-=-=-=-=-=-=-=-=
timestretcher
// TODO: MAYBE SET FEEDBAKC
// void setFeedback
// TODO: BPM INTEREGRATION
// TODO: interpolatie toevoegen om clicks te voorkomen -- maybe
// TODO variable buffer length -- multiple buffers for overlap of buffers


waveshaper
//TODO: rms control
the issue is that the setslope reinitialises the entire buffer which takes time so cant be called during audio loop


float m_rmsSignal;
double m_slopeAmplifier = 0.1;


m_rmsSignal = rms.trackSignal(input);
setSlope(m_rmsSignal * m_slopeAplifier);
