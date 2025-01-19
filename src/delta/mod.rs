use macroquad::time;

const DEFAULT_DELTA_MUL: f32 = 1.0;

pub struct Delta {
    delta: f32,
    multiplier: f32
}

pub fn create() -> Delta {
    Delta {
        delta: 0.0,
        multiplier: DEFAULT_DELTA_MUL
    }
}

impl Delta {
    pub fn set_multiplier(&mut self, value: f32) {
        self.multiplier = value;
    }

    pub fn update(&mut self) {
        self.delta = time::get_frame_time() * self.multiplier;
    }

    pub fn get(&mut self) -> f32 {
        self.delta
    }
}