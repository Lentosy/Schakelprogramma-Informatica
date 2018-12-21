export class Annotation{
    _id: string;
    videoId: string;
    userId: string;
    beginTime: number;
    endTime: number;

    description: string;

    constructor(){
        this.videoId = null;
        this.userId = null;
        this.beginTime=null;
        this.endTime=null;
        this.description = "";
    }
}
