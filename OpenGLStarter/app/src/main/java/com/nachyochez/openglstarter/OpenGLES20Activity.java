package com.nachyochez.openglstarter;

import android.opengl.GLSurfaceView;

/**
 * Created by Kevin on 1/7/2016.
 */
public class OpenGLES20Activity extends Activity
{
    private GLSurfaceView mGLView;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        //Creates a GLSurfaceView instance and set it as the contentView
        mGLView = new MyGLSurfaceView(this);
        setContentView(mGLView);
    }
}
