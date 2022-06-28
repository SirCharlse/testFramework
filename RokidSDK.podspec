
Pod::Spec.new do |spec|

  spec.name         = "YZAppSpSDK"
  spec.version      = "0.0.1"
  spec.summary      = "A short description of YZAppSpSDK."
  spec.description  = <<-DESC
                       XXEncryptKit description
                       DESC

  spec.homepage     = "http://EXAMPLE/YZAppSpSDK"
  spec.license      = "MIT"
  spec.author       = { "Charles" => "297779005@qq.com" }

  spec.platform     = :ios, "10.0"

  spec.source       = { :git => "http://expert.rokid.com/RokidSDK.git", :tag => "#{spec.version}" }

  spec.vendored_frameworks = 'frameworks/*.framework'
  spec.resources = 'RKResources/*.bundle'
  
  spec.requires_arc = true

  spec.dependency "Moya"
  spec.dependency "Kingfisher", "~> 4.10.1"
  spec.dependency "SnapKit", "~> 4.2.0"
  spec.dependency "Then", "~> 2.7.0"
  spec.dependency "IQKeyboardManager", "~> 6.5.6"
  spec.dependency "RKIMCore"
  spec.dependency "RKSocket"
  spec.dependency "JXPhotoBrowser"
  spec.dependency 'RKILogger'
  spec.dependency 'QMUIKit'
  spec.dependency 'PullToRefreshKit'

  # APP
  spec.dependency "Bugly"
  
  # Debug
  spec.dependency "LookinServer"#, :configurations => ['Debug']

  spec.dependency 'RKRTC'
  spec.dependency 'RKCooperationCore'

   #将snc copy到mainBundle
  spec.resource_bundles = {
    'RokidSDK' => ['RokidSDK/Resource/Assets.xcassets','RokidSDK/Resource/*.mp3']
  }



end
