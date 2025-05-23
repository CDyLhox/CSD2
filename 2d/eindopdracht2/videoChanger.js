const positiveVideos = [
	"assets/videos/1960sPlayground1.webm",
	"assets/videos/drone.webm",
	"assets/videos/forest.webm"
];

const negativeVideos = [
	"assets/videos/londerSmog.webm",
	"assets/videos/lightning.webm"
]

let videoContainer = document.createElement('div');
videoContainer.className = "videoContainer";

let positiveWrapper = document.createElement('div');
positiveWrapper.id = "positiveVideoContainer";

let negativeWrapper = document.createElement('div');
negativeWrapper.id = "negativeVideoContainer";

let positiveVideo = document.createElement('video');
let negativeVideo = document.createElement('video');

positiveVideo.autoplay = negativeVideo.autoplay = true;
positiveVideo.loop = negativeVideo.loop = false;
positiveVideo.muted = true;
negativeVideo.muted = true;
negativeVideo.volume = 0.2;

positiveWrapper.appendChild(positiveVideo);
negativeWrapper.appendChild(negativeVideo);

videoContainer.appendChild(negativeWrapper);
videoContainer.appendChild(positiveWrapper);

document.body.appendChild(videoContainer);




console.log(document.getElementById("positiveVideoContainer").getAttribute('src'))

function grabNextVideo(type) {
  if (type === "positive") {
    const nextSrc = positiveVideos[Math.floor(Math.random() * positiveVideos.length)];
    positiveVideo.src = nextSrc;
    positiveVideo.load();
    positiveVideo.play();
    console.log("Loaded positive video:", nextSrc);
  } else if (type === "negative") {
    const nextSrc = negativeVideos[Math.floor(Math.random() * negativeVideos.length)];
    negativeVideo.src = nextSrc;
    negativeVideo.load();
    negativeVideo.play();	

negativeVideo.playbackRate = 1.8;
    console.log("Loaded negative video:", nextSrc);
  }
}

grabNextVideo("positive");
grabNextVideo("negative");

// if the last video has ended, make new video
positiveVideo.addEventListener('ended', () => grabNextVideo("positive"));
negativeVideo.addEventListener('ended', () => grabNextVideo("negative"));
