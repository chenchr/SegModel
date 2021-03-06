#include <vector>
#include "caffe/layers/operator/normalize_layer.hpp"

namespace caffe {

template <typename Dtype>
void NormalizeLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) 
{
  

 #if 0
  if (this->blobs_.size() > 0) {
    LOG(INFO) << "Skipping parameter initialization";
  }
  else
  {
    this->blobs_.resize(1);
    this->blobs_[0].reset(new Blob<Dtype>(channels,1,1,1));
    caffe_gpu_set(this->blobs_[0]->count(),Dtype(norm_param.scale_value()),this->blobs_[0]->mutable_gpu_data());

		
		if (this->layer_param_.param_size() == 0)
	  {
	  	this->lr_mult().push_back(1);
	  	this->decay_mult().push_back(1);
	  }	
  } 
  #endif
}

template <typename Dtype>
void NormalizeLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) 
{
  int num = bottom[0]->num();
  int channels = bottom[0]->channels();
  int height = bottom[0]->height();
  int width = bottom[0]->width();

  top[0]->ReshapeLike(*bottom[0]);


  norm_.Reshape(num, 1, height, width);
}


INSTANTIATE_CLASS(NormalizeLayer);
REGISTER_LAYER_CLASS(Normalize);

}  // namespace caffe
