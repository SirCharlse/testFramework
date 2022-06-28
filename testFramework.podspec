Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
 
  spec.name         = "testFramework"
  spec.version      = "0.0.1"
  spec.summary      = "A short description of testFramework."

  spec.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  spec.homepage     = "https://github.com/SirCharlse/testFramework"
  
  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
 
   spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }


  # ――― Author Metadata  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
 
  spec.author             = { "杨朝" => "chao.yang01@rokid.com" }
 

  # ――― Platform Specifics ――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
 
   spec.platform     = :ios, "10.0"
   spec.swift_version = '5.0'


  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  spec.source       = { :git => "https://github.com/SirCharlse/testFramework.git", :tag => "#{spec.version}" }


  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
 
  #spec.source_files  = "Classes", "Classes/**/*.{h,m}"
  #spec.exclude_files = "Classes/Exclude"

  # spec.public_header_files = "Classes/**/*.h"


  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  spec.resources = 'RKResources/*.bundle'

 #将snc copy到mainBundle
 # spec.resource_bundles = {
 #   'testFramework' => ['RokidSDK/Resource/Assets.xcassets','RokidSDK/Resource/*.mp3']
 # }


  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  spec.vendored_frameworks = 'frameworks/*.framework'

  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
 

  # spec.requires_arc = true

  spec.dependency "Moya"
  spec.dependency "Kingfisher", "~> 4.10.1"
  spec.dependency "SnapKit", "~> 4.2.0"
  spec.dependency "Then", "~> 2.7.0"
  spec.dependency "IQKeyboardManager", "~> 6.5.6"
 # spec.dependency "RKIMCore"
 # spec.dependency "RKSocket"
  spec.dependency "JXPhotoBrowser"
  spec.dependency 'RKILogger'
  spec.dependency 'QMUIKit'
  spec.dependency 'PullToRefreshKit'

  # APP
  spec.dependency "Bugly"
  
  # Debug
  spec.dependency "LookinServer"#, :configurations => ['Debug']

 # spec.dependency 'RKRTC'
 # spec.dependency 'RKCooperationCore'

end
