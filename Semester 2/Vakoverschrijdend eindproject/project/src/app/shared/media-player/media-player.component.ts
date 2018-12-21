import {Component, EventEmitter, Input, OnInit, Output} from '@angular/core';
import {VgAPI} from "videogular2/core";

@Component({
  selector: 'app-media-player',
  template: `
    <vg-player (onPlayerReady)="onPlayerReady($event)">
      <vg-overlay-play></vg-overlay-play>
      <vg-buffering></vg-buffering>

      <vg-scrub-bar>
        <vg-scrub-bar-current-time></vg-scrub-bar-current-time>
        <vg-scrub-bar-buffering-time></vg-scrub-bar-buffering-time>
      </vg-scrub-bar>

      <vg-controls>
        <vg-play-pause></vg-play-pause>

        <vg-time-display vgProperty="current" vgFormat="mm:ss"></vg-time-display>

        <vg-scrub-bar style="pointer-events: none;"></vg-scrub-bar>

        <vg-mute></vg-mute>
        <vg-volume></vg-volume>

        <vg-fullscreen></vg-fullscreen>
      </vg-controls>

      <video [vgMedia]="media" #media id="singleVideo" preload="auto" crossorigin>
        <source src="{{src}}" type="video/mp4">
      </video>
    </vg-player>
  `,
  styleUrls: ['./media-player.component.scss']
})
export class MediaPlayerComponent {

  @Input() src: string;
  @Input() type: string;
  @Output() apiEmmiter: EventEmitter<VgAPI> = new EventEmitter<VgAPI>();

  constructor() {
  }

  onPlayerReady(api: VgAPI) {
    this.apiEmmiter.emit(api);
  }

}
