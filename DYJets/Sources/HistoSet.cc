




<!DOCTYPE html>
<html lang="en" class="   ">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta http-equiv="Content-Language" content="en">
    
    
    <title>TreeAnalysis/HistoSet.cc at master · iihe-cms-sw/TreeAnalysis · GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub">
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png">
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png">
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png">
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png">
    <meta property="fb:app_id" content="1401488693436528">

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="iihe-cms-sw/TreeAnalysis" name="twitter:title" /><meta content="TreeAnalysis - Second step and end of the V + jets analysis. Making bonzais from ntuples and cross section measurements." name="twitter:description" /><meta content="https://avatars0.githubusercontent.com/u/5691170?v=2&amp;s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://avatars0.githubusercontent.com/u/5691170?v=2&amp;s=400" property="og:image" /><meta content="iihe-cms-sw/TreeAnalysis" property="og:title" /><meta content="https://github.com/iihe-cms-sw/TreeAnalysis" property="og:url" /><meta content="TreeAnalysis - Second step and end of the V + jets analysis. Making bonzais from ntuples and cross section measurements." property="og:description" />

    <link rel="assets" href="https://assets-cdn.github.com/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035">
    

    <meta name="msapplication-TileImage" content="/windows-tile.png">
    <meta name="msapplication-TileColor" content="#ffffff">
    <meta name="selected-link" value="repo_source" data-pjax-transient>
      <meta name="google-analytics" content="UA-3769691-2">

    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="C1BEF7C0:7B5B:3E8F655:53EC9B8F" name="octolytics-dimension-request_id" />
    

    
    
    <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico">


    <meta content="authenticity_token" name="csrf-param" />
<meta content="9OKgOxf8oil6rMmACUh4cnTGzJ8Cbo9xmCokR9ErBURIgBaxcFv7v8JXKtC2EMMd9hszv3r/cbp21jIK+jB6lw==" name="csrf-token" />

    <link href="https://assets-cdn.github.com/assets/github-9292d024f6948334bdb496c5e7a55d8df86fb80e.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://assets-cdn.github.com/assets/github2-fe2778113a79ed0985eedf979a34188ceea23f97.css" media="all" rel="stylesheet" type="text/css" />
    


    <meta http-equiv="x-pjax-version" content="f4d07a70fe9c693bc8f53c5731e8976d">

      
  <meta name="description" content="TreeAnalysis - Second step and end of the V + jets analysis. Making bonzais from ntuples and cross section measurements.">


  <meta content="5691170" name="octolytics-dimension-user_id" /><meta content="iihe-cms-sw" name="octolytics-dimension-user_login" /><meta content="14012874" name="octolytics-dimension-repository_id" /><meta content="iihe-cms-sw/TreeAnalysis" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="14012874" name="octolytics-dimension-repository_network_root_id" /><meta content="iihe-cms-sw/TreeAnalysis" name="octolytics-dimension-repository_network_root_nwo" />

  <link href="https://github.com/iihe-cms-sw/TreeAnalysis/commits/master.atom" rel="alternate" title="Recent Commits to TreeAnalysis:master" type="application/atom+xml">

  </head>


  <body class="logged_out  env-production  vis-public page-blob">
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      
      


      
      <div class="header header-logged-out">
  <div class="container clearfix">

    <a class="header-logo-wordmark" href="https://github.com/">
      <span class="mega-octicon octicon-logo-github"></span>
    </a>

    <div class="header-actions">
        <a class="button primary" href="/join">Sign up</a>
      <a class="button signin" href="/login?return_to=%2Fiihe-cms-sw%2FTreeAnalysis%2Fblob%2Fmaster%2FDYJets%2FSources%2FHistoSet.cc">Sign in</a>
    </div>

    <div class="command-bar js-command-bar  in-repository">

      <ul class="top-nav">
          <li class="explore"><a href="/explore">Explore</a></li>
          <li class="features"><a href="/features">Features</a></li>
          <li class="enterprise"><a href="https://enterprise.github.com/">Enterprise</a></li>
          <li class="blog"><a href="/blog">Blog</a></li>
      </ul>
        <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">

<div class="commandbar">
  <span class="message"></span>
  <input type="text" data-hotkey="s, /" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    
    
    data-repo="iihe-cms-sw/TreeAnalysis"
  >
  <div class="display hidden"></div>
</div>

    <input type="hidden" name="nwo" value="iihe-cms-sw/TreeAnalysis">

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target" role="button" aria-haspopup="true">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container" aria-hidden="true">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item js-this-repository-navigation-item selected">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked">
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item js-all-repositories-navigation-item">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" name="search_target" value="global">
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="help tooltipped tooltipped-s" aria-label="Show command bar help">
    <span class="octicon octicon-question"></span>
  </span>


  <input type="hidden" name="ref" value="cmdform">

</form>
    </div>

  </div>
</div>



      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    <div id="js-flash-container">
      
    </div>
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        
<ul class="pagehead-actions">


  <li>
      <a href="/login?return_to=%2Fiihe-cms-sw%2FTreeAnalysis"
    class="minibutton with-count star-button tooltipped tooltipped-n"
    aria-label="You must be signed in to star a repository" rel="nofollow">
    <span class="octicon octicon-star"></span>
    Star
  </a>

    <a class="social-count js-social-count" href="/iihe-cms-sw/TreeAnalysis/stargazers">
      0
    </a>

  </li>

    <li>
      <a href="/login?return_to=%2Fiihe-cms-sw%2FTreeAnalysis"
        class="minibutton with-count js-toggler-target fork-button tooltipped tooltipped-n"
        aria-label="You must be signed in to fork a repository" rel="nofollow">
        <span class="octicon octicon-repo-forked"></span>
        Fork
      </a>
      <a href="/iihe-cms-sw/TreeAnalysis/network" class="social-count">
        1
      </a>
    </li>
</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="mega-octicon octicon-repo"></span>
          <span class="author"><a href="/iihe-cms-sw" class="url fn" itemprop="url" rel="author"><span itemprop="title">iihe-cms-sw</span></a></span><!--
       --><span class="path-divider">/</span><!--
       --><strong><a href="/iihe-cms-sw/TreeAnalysis" class="js-current-repository js-repo-home-link">TreeAnalysis</a></strong>

          <span class="page-context-loader">
            <img alt="" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      <div class="repository-with-sidebar repo-container new-discussion-timeline  ">
        <div class="repository-sidebar clearfix">
            

<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders" data-issue-count-url="/iihe-cms-sw/TreeAnalysis/issues/counts">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped tooltipped-w" aria-label="Code">
        <a href="/iihe-cms-sw/TreeAnalysis" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-hotkey="g c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_releases repo_tags repo_branches /iihe-cms-sw/TreeAnalysis">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

        <li class="tooltipped tooltipped-w" aria-label="Issues">
          <a href="/iihe-cms-sw/TreeAnalysis/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g i" data-selected-links="repo_issues repo_labels repo_milestones /iihe-cms-sw/TreeAnalysis/issues">
            <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
            <span class="js-issue-replace-counter"></span>
            <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>

      <li class="tooltipped tooltipped-w" aria-label="Pull Requests">
        <a href="/iihe-cms-sw/TreeAnalysis/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-hotkey="g p" data-selected-links="repo_pulls /iihe-cms-sw/TreeAnalysis/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class="js-pull-replace-counter"></span>
            <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped tooltipped-w" aria-label="Pulse">
        <a href="/iihe-cms-sw/TreeAnalysis/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /iihe-cms-sw/TreeAnalysis/pulse">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Graphs">
        <a href="/iihe-cms-sw/TreeAnalysis/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /iihe-cms-sw/TreeAnalysis/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="" class="mini-loader" height="16" src="https://assets-cdn.github.com/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


  </div>
</div>

              <div class="only-with-full-nav">
                

  

<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=clone">
  <h3><strong>HTTPS</strong> clone URL</h3>
  <div class="input-group">
    <input type="text" class="input-mini input-monospace js-url-field"
           value="https://github.com/iihe-cms-sw/TreeAnalysis.git" readonly="readonly">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/iihe-cms-sw/TreeAnalysis.git" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=clone">
  <h3><strong>Subversion</strong> checkout URL</h3>
  <div class="input-group">
    <input type="text" class="input-mini input-monospace js-url-field"
           value="https://github.com/iihe-cms-sw/TreeAnalysis" readonly="readonly">
    <span class="input-group-button">
      <button aria-label="Copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="https://github.com/iihe-cms-sw/TreeAnalysis" data-copied-hint="Copied!" type="button"><span class="octicon octicon-clippy"></span></button>
    </span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <a href="https://help.github.com/articles/which-remote-url-should-i-use" class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
    <span class="octicon octicon-question"></span>
  </a>
</p>



                <a href="/iihe-cms-sw/TreeAnalysis/archive/master.zip"
                   class="minibutton sidebar-button"
                   aria-label="Download iihe-cms-sw/TreeAnalysis as a zip file"
                   title="Download iihe-cms-sw/TreeAnalysis as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          


<a href="/iihe-cms-sw/TreeAnalysis/blob/e6b7ecdc8f276abab9f363235efaaf59651338de/DYJets/Sources/HistoSet.cc" class="hidden js-permalink-shortcut" data-hotkey="y">Permalink</a>

<!-- blob contrib key: blob_contributors:v21:75834645914bfee15bfad78773db1293 -->

<div class="file-navigation">
  

<div class="select-menu js-menu-container js-select-menu left">
  <span class="minibutton select-menu-button js-menu-target css-truncate" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    title="master"
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button css-truncate-target">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-x js-menu-close" role="button" aria-label="Close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/iihe-cms-sw/TreeAnalysis/blob/master/DYJets/Sources/HistoSet.cc"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="button-group right">
    <a href="/iihe-cms-sw/TreeAnalysis/find/master"
          class="js-show-file-finder minibutton empty-icon tooltipped tooltipped-s"
          data-pjax
          data-hotkey="t"
          aria-label="Quickly jump between files">
      <span class="octicon octicon-list-unordered"></span>
    </a>
    <button class="js-zeroclipboard minibutton zeroclipboard-button"
          data-clipboard-text="DYJets/Sources/HistoSet.cc"
          aria-label="Copy to clipboard"
          data-copied-hint="Copied!">
      <span class="octicon octicon-clippy"></span>
    </button>
  </div>

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/iihe-cms-sw/TreeAnalysis" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">TreeAnalysis</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/iihe-cms-sw/TreeAnalysis/tree/master/DYJets" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">DYJets</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/iihe-cms-sw/TreeAnalysis/tree/master/DYJets/Sources" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">Sources</span></a></span><span class="separator"> / </span><strong class="final-path">HistoSet.cc</strong>
  </div>
</div>


  <div class="commit file-history-tease">
      <img alt="aleonard-cern" class="main-avatar" data-user="5367419" height="24" src="https://avatars0.githubusercontent.com/u/5367419?v=2&amp;s=48" width="24" />
      <span class="author"><a href="/aleonard-cern" rel="contributor">aleonard-cern</a></span>
      <time datetime="2014-07-01T09:29:35+02:00" is="relative-time">July 01, 2014</time>
      <div class="commit-title">
          <a href="/iihe-cms-sw/TreeAnalysis/commit/e6b7ecdc8f276abab9f363235efaaf59651338de" class="message" data-pjax="true" title="some change has been done since last time">some change has been done since last time</a>
      </div>

    <div class="participation">
      <p class="quickstat"><a href="#blob_contributors_box" rel="facebox"><strong>2</strong>  contributors</a></p>
      
    <a class="avatar tooltipped tooltipped-s" aria-label="aleonard-cern" href="/iihe-cms-sw/TreeAnalysis/commits/master/DYJets/Sources/HistoSet.cc?author=aleonard-cern"><img alt="aleonard-cern" data-user="5367419" height="20" src="https://avatars2.githubusercontent.com/u/5367419?v=2&amp;s=40" width="20" /></a>
    <a class="avatar tooltipped tooltipped-s" aria-label="tseva" href="/iihe-cms-sw/TreeAnalysis/commits/master/DYJets/Sources/HistoSet.cc?author=tseva"><img alt="tseva" data-user="4799402" height="20" src="https://avatars1.githubusercontent.com/u/4799402?v=2&amp;s=40" width="20" /></a>


    </div>
    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list">
          <li class="facebox-user-list-item">
            <img alt="aleonard-cern" data-user="5367419" height="24" src="https://avatars0.githubusercontent.com/u/5367419?v=2&amp;s=48" width="24" />
            <a href="/aleonard-cern">aleonard-cern</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="tseva" data-user="4799402" height="24" src="https://avatars3.githubusercontent.com/u/4799402?v=2&amp;s=48" width="24" />
            <a href="/tseva">tseva</a>
          </li>
      </ul>
    </div>
  </div>

<div class="file-box">
  <div class="file">
    <div class="meta clearfix">
      <div class="info file-name">
          <span>1754 lines (1450 sloc)</span>
          <span class="meta-divider"></span>
        <span>183.719 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
          <a href="/iihe-cms-sw/TreeAnalysis/raw/master/DYJets/Sources/HistoSet.cc" class="minibutton " id="raw-url">Raw</a>
            <a href="/iihe-cms-sw/TreeAnalysis/blame/master/DYJets/Sources/HistoSet.cc" class="minibutton js-update-url-with-hash">Blame</a>
          <a href="/iihe-cms-sw/TreeAnalysis/commits/master/DYJets/Sources/HistoSet.cc" class="minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->


            <a class="octicon-button disabled tooltipped tooltipped-w" href="#"
               aria-label="You must be signed in to make or propose changes"><span class="octicon octicon-pencil"></span></a>

          <a class="octicon-button danger disabled tooltipped tooltipped-w" href="#"
             aria-label="You must be signed in to make or propose changes">
          <span class="octicon octicon-trashcan"></span>
        </a>
      </div><!-- /.actions -->
    </div>
      
  <div class="blob-wrapper data type-c">
      <table class="highlight tab-size-8 js-file-line-container">
      <tr>
        <td id="L1" class="blob-line-num js-line-number" data-line-number="1"></td>
        <td id="LC1" class="blob-line-code js-file-line"><span class="cp">#define PI 3.14159265359</span></td>
      </tr>
      <tr>
        <td id="L2" class="blob-line-num js-line-number" data-line-number="2"></td>
        <td id="LC2" class="blob-line-code js-file-line"><span class="cp">#include &lt;iostream&gt;</span></td>
      </tr>
      <tr>
        <td id="L3" class="blob-line-num js-line-number" data-line-number="3"></td>
        <td id="LC3" class="blob-line-code js-file-line"><span class="cp">#include &lt;TH1.h&gt;</span></td>
      </tr>
      <tr>
        <td id="L4" class="blob-line-num js-line-number" data-line-number="4"></td>
        <td id="LC4" class="blob-line-code js-file-line"><span class="cp">#include &lt;TH2.h&gt;</span></td>
      </tr>
      <tr>
        <td id="L5" class="blob-line-num js-line-number" data-line-number="5"></td>
        <td id="LC5" class="blob-line-code js-file-line"><span class="cp">#include &lt;RooUnfoldResponse.h&gt;</span></td>
      </tr>
      <tr>
        <td id="L6" class="blob-line-num js-line-number" data-line-number="6"></td>
        <td id="LC6" class="blob-line-code js-file-line"><span class="cp">#include &quot;HistoSet.h&quot;</span></td>
      </tr>
      <tr>
        <td id="L7" class="blob-line-num js-line-number" data-line-number="7"></td>
        <td id="LC7" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L8" class="blob-line-num js-line-number" data-line-number="8"></td>
        <td id="LC8" class="blob-line-code js-file-line"><span class="k">using</span> <span class="k">namespace</span> <span class="n">std</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L9" class="blob-line-num js-line-number" data-line-number="9"></td>
        <td id="LC9" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L10" class="blob-line-num js-line-number" data-line-number="10"></td>
        <td id="LC10" class="blob-line-code js-file-line"><span class="n">ClassImp</span><span class="p">(</span><span class="n">HistoSet</span><span class="p">)</span></td>
      </tr>
      <tr>
        <td id="L11" class="blob-line-num js-line-number" data-line-number="11"></td>
        <td id="LC11" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L12" class="blob-line-num js-line-number" data-line-number="12"></td>
        <td id="LC12" class="blob-line-code js-file-line"><span class="n">HistoSet</span><span class="o">::~</span><span class="n">HistoSet</span><span class="p">()</span></td>
      </tr>
      <tr>
        <td id="L13" class="blob-line-num js-line-number" data-line-number="13"></td>
        <td id="LC13" class="blob-line-code js-file-line"><span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L14" class="blob-line-num js-line-number" data-line-number="14"></td>
        <td id="LC14" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L15" class="blob-line-num js-line-number" data-line-number="15"></td>
        <td id="LC15" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L16" class="blob-line-num js-line-number" data-line-number="16"></td>
        <td id="LC16" class="blob-line-code js-file-line"><span class="n">vector</span><span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">makeVector</span><span class="p">(</span><span class="kt">int</span> <span class="n">num</span><span class="p">,</span> <span class="p">...)</span></td>
      </tr>
      <tr>
        <td id="L17" class="blob-line-num js-line-number" data-line-number="17"></td>
        <td id="LC17" class="blob-line-code js-file-line"><span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L18" class="blob-line-num js-line-number" data-line-number="18"></td>
        <td id="LC18" class="blob-line-code js-file-line">    <span class="kt">va_list</span> <span class="n">list</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L19" class="blob-line-num js-line-number" data-line-number="19"></td>
        <td id="LC19" class="blob-line-code js-file-line">    <span class="n">va_start</span><span class="p">(</span><span class="n">list</span><span class="p">,</span> <span class="n">num</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L20" class="blob-line-num js-line-number" data-line-number="20"></td>
        <td id="LC20" class="blob-line-code js-file-line">    <span class="n">vector</span><span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;</span> <span class="n">vec</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L21" class="blob-line-num js-line-number" data-line-number="21"></td>
        <td id="LC21" class="blob-line-code js-file-line">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="p">(</span><span class="mi">0</span><span class="p">);</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">num</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L22" class="blob-line-num js-line-number" data-line-number="22"></td>
        <td id="LC22" class="blob-line-code js-file-line">        <span class="kt">double</span> <span class="n">next</span> <span class="o">=</span> <span class="n">va_arg</span><span class="p">(</span><span class="n">list</span><span class="p">,</span> <span class="kt">double</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L23" class="blob-line-num js-line-number" data-line-number="23"></td>
        <td id="LC23" class="blob-line-code js-file-line">        <span class="n">vec</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">next</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L24" class="blob-line-num js-line-number" data-line-number="24"></td>
        <td id="LC24" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L25" class="blob-line-num js-line-number" data-line-number="25"></td>
        <td id="LC25" class="blob-line-code js-file-line">    <span class="n">va_end</span><span class="p">(</span><span class="n">list</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L26" class="blob-line-num js-line-number" data-line-number="26"></td>
        <td id="LC26" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">vec</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L27" class="blob-line-num js-line-number" data-line-number="27"></td>
        <td id="LC27" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L28" class="blob-line-num js-line-number" data-line-number="28"></td>
        <td id="LC28" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L29" class="blob-line-num js-line-number" data-line-number="29"></td>
        <td id="LC29" class="blob-line-code js-file-line"><span class="kt">void</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">insertVector</span><span class="p">(</span><span class="n">vector</span><span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;&amp;</span> <span class="n">veca</span><span class="p">,</span> <span class="kt">int</span> <span class="n">num</span><span class="p">,</span> <span class="p">...)</span></td>
      </tr>
      <tr>
        <td id="L30" class="blob-line-num js-line-number" data-line-number="30"></td>
        <td id="LC30" class="blob-line-code js-file-line"><span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L31" class="blob-line-num js-line-number" data-line-number="31"></td>
        <td id="LC31" class="blob-line-code js-file-line">    <span class="kt">va_list</span> <span class="n">list</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L32" class="blob-line-num js-line-number" data-line-number="32"></td>
        <td id="LC32" class="blob-line-code js-file-line">    <span class="n">va_start</span><span class="p">(</span><span class="n">list</span><span class="p">,</span> <span class="n">num</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L33" class="blob-line-num js-line-number" data-line-number="33"></td>
        <td id="LC33" class="blob-line-code js-file-line">    <span class="n">vector</span><span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;</span> <span class="n">vecb</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L34" class="blob-line-num js-line-number" data-line-number="34"></td>
        <td id="LC34" class="blob-line-code js-file-line">    <span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span><span class="p">(</span><span class="mi">0</span><span class="p">);</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">num</span><span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L35" class="blob-line-num js-line-number" data-line-number="35"></td>
        <td id="LC35" class="blob-line-code js-file-line">        <span class="kt">double</span> <span class="n">next</span> <span class="o">=</span> <span class="n">va_arg</span><span class="p">(</span><span class="n">list</span><span class="p">,</span> <span class="kt">double</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L36" class="blob-line-num js-line-number" data-line-number="36"></td>
        <td id="LC36" class="blob-line-code js-file-line">        <span class="n">vecb</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">next</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L37" class="blob-line-num js-line-number" data-line-number="37"></td>
        <td id="LC37" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L38" class="blob-line-num js-line-number" data-line-number="38"></td>
        <td id="LC38" class="blob-line-code js-file-line">    <span class="n">va_end</span><span class="p">(</span><span class="n">list</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L39" class="blob-line-num js-line-number" data-line-number="39"></td>
        <td id="LC39" class="blob-line-code js-file-line">    <span class="n">veca</span><span class="p">.</span><span class="n">insert</span><span class="p">(</span><span class="n">veca</span><span class="p">.</span><span class="n">end</span><span class="p">(),</span> <span class="n">vecb</span><span class="p">.</span><span class="n">begin</span><span class="p">(),</span> <span class="n">vecb</span><span class="p">.</span><span class="n">end</span><span class="p">());</span></td>
      </tr>
      <tr>
        <td id="L40" class="blob-line-num js-line-number" data-line-number="40"></td>
        <td id="LC40" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L41" class="blob-line-num js-line-number" data-line-number="41"></td>
        <td id="LC41" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L42" class="blob-line-num js-line-number" data-line-number="42"></td>
        <td id="LC42" class="blob-line-code js-file-line"><span class="n">TH1D</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newTH1D</span><span class="p">(</span><span class="n">string</span> <span class="n">name</span><span class="p">,</span> <span class="n">string</span> <span class="n">title</span><span class="p">,</span> <span class="n">string</span> <span class="n">xTitle</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBins</span><span class="p">,</span> <span class="kt">double</span> <span class="o">*</span><span class="n">xBins</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L43" class="blob-line-num js-line-number" data-line-number="43"></td>
        <td id="LC43" class="blob-line-code js-file-line">    <span class="n">TH1D</span><span class="o">*</span> <span class="n">hist</span> <span class="o">=</span> <span class="k">new</span> <span class="n">TH1D</span><span class="p">(</span><span class="n">name</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">title</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">nBins</span><span class="p">,</span> <span class="n">xBins</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L44" class="blob-line-num js-line-number" data-line-number="44"></td>
        <td id="LC44" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="n">xTitle</span><span class="p">.</span><span class="n">c_str</span><span class="p">());</span></td>
      </tr>
      <tr>
        <td id="L45" class="blob-line-num js-line-number" data-line-number="45"></td>
        <td id="LC45" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetYaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="s">&quot;# Events&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L46" class="blob-line-num js-line-number" data-line-number="46"></td>
        <td id="LC46" class="blob-line-code js-file-line">    <span class="n">listOfHistograms</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">hist</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L47" class="blob-line-num js-line-number" data-line-number="47"></td>
        <td id="LC47" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">hist</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L48" class="blob-line-num js-line-number" data-line-number="48"></td>
        <td id="LC48" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L49" class="blob-line-num js-line-number" data-line-number="49"></td>
        <td id="LC49" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L50" class="blob-line-num js-line-number" data-line-number="50"></td>
        <td id="LC50" class="blob-line-code js-file-line"><span class="n">TH1D</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newTH1D</span><span class="p">(</span><span class="n">string</span> <span class="n">name</span><span class="p">,</span> <span class="n">string</span> <span class="n">title</span><span class="p">,</span> <span class="n">string</span> <span class="n">xTitle</span><span class="p">,</span> <span class="n">vector</span><span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;&amp;</span> <span class="n">xBinsVect</span><span class="p">)</span></td>
      </tr>
      <tr>
        <td id="L51" class="blob-line-num js-line-number" data-line-number="51"></td>
        <td id="LC51" class="blob-line-code js-file-line"><span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L52" class="blob-line-num js-line-number" data-line-number="52"></td>
        <td id="LC52" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="n">nBins</span> <span class="o">=</span> <span class="n">xBinsVect</span><span class="p">.</span><span class="n">size</span><span class="p">()</span><span class="o">-</span><span class="mi">1</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L53" class="blob-line-num js-line-number" data-line-number="53"></td>
        <td id="LC53" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="o">*</span><span class="n">xBins</span> <span class="o">=</span> <span class="k">new</span> <span class="kt">double</span><span class="p">[</span><span class="n">xBinsVect</span><span class="p">.</span><span class="n">size</span><span class="p">()];</span></td>
      </tr>
      <tr>
        <td id="L54" class="blob-line-num js-line-number" data-line-number="54"></td>
        <td id="LC54" class="blob-line-code js-file-line">    <span class="n">std</span><span class="o">::</span><span class="n">copy</span><span class="p">(</span><span class="n">xBinsVect</span><span class="p">.</span><span class="n">begin</span><span class="p">(),</span> <span class="n">xBinsVect</span><span class="p">.</span><span class="n">end</span><span class="p">(),</span> <span class="n">xBins</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L55" class="blob-line-num js-line-number" data-line-number="55"></td>
        <td id="LC55" class="blob-line-code js-file-line">    <span class="n">TH1D</span><span class="o">*</span> <span class="n">hist</span> <span class="o">=</span> <span class="k">new</span> <span class="n">TH1D</span><span class="p">(</span><span class="n">name</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">title</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">nBins</span><span class="p">,</span> <span class="n">xBins</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L56" class="blob-line-num js-line-number" data-line-number="56"></td>
        <td id="LC56" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="n">xTitle</span><span class="p">.</span><span class="n">c_str</span><span class="p">());</span></td>
      </tr>
      <tr>
        <td id="L57" class="blob-line-num js-line-number" data-line-number="57"></td>
        <td id="LC57" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetYaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="s">&quot;# Events&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L58" class="blob-line-num js-line-number" data-line-number="58"></td>
        <td id="LC58" class="blob-line-code js-file-line">    <span class="k">delete</span> <span class="p">[]</span> <span class="n">xBins</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L59" class="blob-line-num js-line-number" data-line-number="59"></td>
        <td id="LC59" class="blob-line-code js-file-line">    <span class="n">listOfHistograms</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">hist</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L60" class="blob-line-num js-line-number" data-line-number="60"></td>
        <td id="LC60" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">hist</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L61" class="blob-line-num js-line-number" data-line-number="61"></td>
        <td id="LC61" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L62" class="blob-line-num js-line-number" data-line-number="62"></td>
        <td id="LC62" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L63" class="blob-line-num js-line-number" data-line-number="63"></td>
        <td id="LC63" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L64" class="blob-line-num js-line-number" data-line-number="64"></td>
        <td id="LC64" class="blob-line-code js-file-line"><span class="n">TH1D</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newTH1D</span><span class="p">(</span><span class="n">string</span> <span class="n">name</span><span class="p">,</span> <span class="n">string</span> <span class="n">title</span><span class="p">,</span> <span class="n">string</span> <span class="n">xTitle</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBins</span><span class="p">,</span> <span class="kt">double</span> <span class="n">xLow</span><span class="p">,</span> <span class="kt">double</span> <span class="n">xUp</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L65" class="blob-line-num js-line-number" data-line-number="65"></td>
        <td id="LC65" class="blob-line-code js-file-line">    <span class="n">TH1D</span><span class="o">*</span> <span class="n">hist</span> <span class="o">=</span> <span class="k">new</span> <span class="n">TH1D</span><span class="p">(</span><span class="n">name</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">title</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">nBins</span><span class="p">,</span> <span class="n">xLow</span><span class="p">,</span> <span class="n">xUp</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L66" class="blob-line-num js-line-number" data-line-number="66"></td>
        <td id="LC66" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="n">xTitle</span><span class="p">.</span><span class="n">c_str</span><span class="p">());</span></td>
      </tr>
      <tr>
        <td id="L67" class="blob-line-num js-line-number" data-line-number="67"></td>
        <td id="LC67" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetYaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="s">&quot;# Events&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L68" class="blob-line-num js-line-number" data-line-number="68"></td>
        <td id="LC68" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">SetOption</span><span class="p">(</span><span class="s">&quot;HIST&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L69" class="blob-line-num js-line-number" data-line-number="69"></td>
        <td id="LC69" class="blob-line-code js-file-line">    <span class="n">listOfHistograms</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">hist</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L70" class="blob-line-num js-line-number" data-line-number="70"></td>
        <td id="LC70" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">hist</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L71" class="blob-line-num js-line-number" data-line-number="71"></td>
        <td id="LC71" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L72" class="blob-line-num js-line-number" data-line-number="72"></td>
        <td id="LC72" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L73" class="blob-line-num js-line-number" data-line-number="73"></td>
        <td id="LC73" class="blob-line-code js-file-line"><span class="n">TH2D</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newTH2D</span><span class="p">(</span><span class="n">string</span> <span class="n">name</span><span class="p">,</span> <span class="n">string</span> <span class="n">title</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBinsX</span><span class="p">,</span> <span class="kt">double</span> <span class="o">*</span><span class="n">xBins</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBinsY</span><span class="p">,</span> <span class="kt">double</span> <span class="o">*</span><span class="n">yBinsY</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L74" class="blob-line-num js-line-number" data-line-number="74"></td>
        <td id="LC74" class="blob-line-code js-file-line">    <span class="n">TH2D</span><span class="o">*</span> <span class="n">hist</span> <span class="o">=</span> <span class="k">new</span> <span class="n">TH2D</span><span class="p">(</span><span class="n">name</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">title</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">nBinsX</span><span class="p">,</span> <span class="n">xBins</span><span class="p">,</span> <span class="n">nBinsY</span><span class="p">,</span> <span class="n">yBinsY</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L75" class="blob-line-num js-line-number" data-line-number="75"></td>
        <td id="LC75" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetZaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="s">&quot;# Events&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L76" class="blob-line-num js-line-number" data-line-number="76"></td>
        <td id="LC76" class="blob-line-code js-file-line">    <span class="n">listOfHistograms</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">hist</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L77" class="blob-line-num js-line-number" data-line-number="77"></td>
        <td id="LC77" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">hist</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L78" class="blob-line-num js-line-number" data-line-number="78"></td>
        <td id="LC78" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L79" class="blob-line-num js-line-number" data-line-number="79"></td>
        <td id="LC79" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L80" class="blob-line-num js-line-number" data-line-number="80"></td>
        <td id="LC80" class="blob-line-code js-file-line"><span class="n">TH2D</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newTH2D</span><span class="p">(</span><span class="n">string</span> <span class="n">name</span><span class="p">,</span> <span class="n">string</span> <span class="n">title</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBinsX</span><span class="p">,</span> <span class="kt">double</span> <span class="o">*</span><span class="n">xBins</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBinsY</span><span class="p">,</span> <span class="kt">double</span> <span class="n">yLow</span><span class="p">,</span> <span class="kt">double</span> <span class="n">yUp</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L81" class="blob-line-num js-line-number" data-line-number="81"></td>
        <td id="LC81" class="blob-line-code js-file-line">    <span class="n">TH2D</span><span class="o">*</span> <span class="n">hist</span> <span class="o">=</span> <span class="k">new</span> <span class="n">TH2D</span><span class="p">(</span><span class="n">name</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">title</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">nBinsX</span><span class="p">,</span> <span class="n">xBins</span><span class="p">,</span> <span class="n">nBinsY</span><span class="p">,</span> <span class="n">yLow</span><span class="p">,</span> <span class="n">yUp</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L82" class="blob-line-num js-line-number" data-line-number="82"></td>
        <td id="LC82" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetZaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="s">&quot;# Events&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L83" class="blob-line-num js-line-number" data-line-number="83"></td>
        <td id="LC83" class="blob-line-code js-file-line">    <span class="n">listOfHistograms</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">hist</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L84" class="blob-line-num js-line-number" data-line-number="84"></td>
        <td id="LC84" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">hist</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L85" class="blob-line-num js-line-number" data-line-number="85"></td>
        <td id="LC85" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L86" class="blob-line-num js-line-number" data-line-number="86"></td>
        <td id="LC86" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L87" class="blob-line-num js-line-number" data-line-number="87"></td>
        <td id="LC87" class="blob-line-code js-file-line"><span class="n">TH2D</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newTH2D</span><span class="p">(</span><span class="n">string</span> <span class="n">name</span><span class="p">,</span> <span class="n">string</span> <span class="n">title</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBinsX</span><span class="p">,</span> <span class="kt">double</span> <span class="n">xLow</span><span class="p">,</span> <span class="kt">double</span> <span class="n">xUp</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBinsY</span><span class="p">,</span> <span class="kt">double</span> <span class="o">*</span><span class="n">yBins</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L88" class="blob-line-num js-line-number" data-line-number="88"></td>
        <td id="LC88" class="blob-line-code js-file-line">    <span class="n">TH2D</span><span class="o">*</span> <span class="n">hist</span> <span class="o">=</span> <span class="k">new</span> <span class="n">TH2D</span><span class="p">(</span><span class="n">name</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">title</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">nBinsX</span><span class="p">,</span> <span class="n">xLow</span><span class="p">,</span> <span class="n">xUp</span><span class="p">,</span> <span class="n">nBinsY</span><span class="p">,</span> <span class="n">yBins</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L89" class="blob-line-num js-line-number" data-line-number="89"></td>
        <td id="LC89" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetZaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="s">&quot;# Events&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L90" class="blob-line-num js-line-number" data-line-number="90"></td>
        <td id="LC90" class="blob-line-code js-file-line">    <span class="n">listOfHistograms</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">hist</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L91" class="blob-line-num js-line-number" data-line-number="91"></td>
        <td id="LC91" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">hist</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L92" class="blob-line-num js-line-number" data-line-number="92"></td>
        <td id="LC92" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L93" class="blob-line-num js-line-number" data-line-number="93"></td>
        <td id="LC93" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L94" class="blob-line-num js-line-number" data-line-number="94"></td>
        <td id="LC94" class="blob-line-code js-file-line"><span class="n">TH2D</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newTH2D</span><span class="p">(</span><span class="n">string</span> <span class="n">name</span><span class="p">,</span> <span class="n">string</span> <span class="n">title</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBinsX</span><span class="p">,</span> <span class="kt">double</span> <span class="n">xLow</span><span class="p">,</span> <span class="kt">double</span> <span class="n">xUp</span><span class="p">,</span> <span class="kt">int</span> <span class="n">nBinsY</span><span class="p">,</span> <span class="kt">double</span> <span class="n">yLow</span><span class="p">,</span> <span class="kt">double</span> <span class="n">yUp</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L95" class="blob-line-num js-line-number" data-line-number="95"></td>
        <td id="LC95" class="blob-line-code js-file-line">    <span class="n">TH2D</span><span class="o">*</span> <span class="n">hist</span> <span class="o">=</span> <span class="k">new</span> <span class="n">TH2D</span><span class="p">(</span><span class="n">name</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">title</span><span class="p">.</span><span class="n">c_str</span><span class="p">(),</span> <span class="n">nBinsX</span><span class="p">,</span> <span class="n">xLow</span><span class="p">,</span> <span class="n">xUp</span><span class="p">,</span> <span class="n">nBinsY</span><span class="p">,</span> <span class="n">yLow</span><span class="p">,</span> <span class="n">yUp</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L96" class="blob-line-num js-line-number" data-line-number="96"></td>
        <td id="LC96" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">GetZaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetTitle</span><span class="p">(</span><span class="s">&quot;# Events&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L97" class="blob-line-num js-line-number" data-line-number="97"></td>
        <td id="LC97" class="blob-line-code js-file-line">    <span class="n">hist</span><span class="o">-&gt;</span><span class="n">SetOption</span><span class="p">(</span><span class="s">&quot;HIST&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L98" class="blob-line-num js-line-number" data-line-number="98"></td>
        <td id="LC98" class="blob-line-code js-file-line">    <span class="n">listOfHistograms</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">hist</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L99" class="blob-line-num js-line-number" data-line-number="99"></td>
        <td id="LC99" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">hist</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L100" class="blob-line-num js-line-number" data-line-number="100"></td>
        <td id="LC100" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L101" class="blob-line-num js-line-number" data-line-number="101"></td>
        <td id="LC101" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L102" class="blob-line-num js-line-number" data-line-number="102"></td>
        <td id="LC102" class="blob-line-code js-file-line"><span class="n">RooUnfoldResponse</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newResp</span><span class="p">(</span><span class="n">TH1D</span><span class="o">*</span> <span class="n">reco</span><span class="p">,</span> <span class="n">TH1D</span><span class="o">*</span> <span class="n">gen</span><span class="p">)</span></td>
      </tr>
      <tr>
        <td id="L103" class="blob-line-num js-line-number" data-line-number="103"></td>
        <td id="LC103" class="blob-line-code js-file-line"><span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L104" class="blob-line-num js-line-number" data-line-number="104"></td>
        <td id="LC104" class="blob-line-code js-file-line">    <span class="n">RooUnfoldResponse</span> <span class="o">*</span><span class="n">response</span> <span class="o">=</span> <span class="k">new</span> <span class="n">RooUnfoldResponse</span><span class="p">(</span><span class="n">reco</span><span class="p">,</span> <span class="n">gen</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L105" class="blob-line-num js-line-number" data-line-number="105"></td>
        <td id="LC105" class="blob-line-code js-file-line">    <span class="n">listOfResponses</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">response</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L106" class="blob-line-num js-line-number" data-line-number="106"></td>
        <td id="LC106" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">response</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L107" class="blob-line-num js-line-number" data-line-number="107"></td>
        <td id="LC107" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L108" class="blob-line-num js-line-number" data-line-number="108"></td>
        <td id="LC108" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L109" class="blob-line-num js-line-number" data-line-number="109"></td>
        <td id="LC109" class="blob-line-code js-file-line"><span class="n">RooUnfoldResponse</span><span class="o">*</span> <span class="n">HistoSet</span><span class="o">::</span><span class="n">newResp</span><span class="p">(</span><span class="n">TH2D</span><span class="o">*</span> <span class="n">reco</span><span class="p">,</span> <span class="n">TH2D</span><span class="o">*</span> <span class="n">gen</span><span class="p">)</span></td>
      </tr>
      <tr>
        <td id="L110" class="blob-line-num js-line-number" data-line-number="110"></td>
        <td id="LC110" class="blob-line-code js-file-line"><span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L111" class="blob-line-num js-line-number" data-line-number="111"></td>
        <td id="LC111" class="blob-line-code js-file-line">    <span class="n">RooUnfoldResponse</span> <span class="o">*</span><span class="n">response</span> <span class="o">=</span> <span class="k">new</span> <span class="n">RooUnfoldResponse</span><span class="p">(</span><span class="n">reco</span><span class="p">,</span> <span class="n">gen</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L112" class="blob-line-num js-line-number" data-line-number="112"></td>
        <td id="LC112" class="blob-line-code js-file-line">    <span class="n">listOfResponses</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">response</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L113" class="blob-line-num js-line-number" data-line-number="113"></td>
        <td id="LC113" class="blob-line-code js-file-line">    <span class="k">return</span> <span class="n">response</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L114" class="blob-line-num js-line-number" data-line-number="114"></td>
        <td id="LC114" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L115" class="blob-line-num js-line-number" data-line-number="115"></td>
        <td id="LC115" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L116" class="blob-line-num js-line-number" data-line-number="116"></td>
        <td id="LC116" class="blob-line-code js-file-line"><span class="n">HistoSet</span><span class="o">::</span><span class="n">HistoSet</span><span class="p">(</span><span class="n">string</span> <span class="n">leptonFlavor</span><span class="p">)</span></td>
      </tr>
      <tr>
        <td id="L117" class="blob-line-num js-line-number" data-line-number="117"></td>
        <td id="LC117" class="blob-line-code js-file-line"><span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L118" class="blob-line-num js-line-number" data-line-number="118"></td>
        <td id="LC118" class="blob-line-code js-file-line">    <span class="n">TH1</span><span class="o">::</span><span class="n">SetDefaultSumw2</span><span class="p">();</span></td>
      </tr>
      <tr>
        <td id="L119" class="blob-line-num js-line-number" data-line-number="119"></td>
        <td id="LC119" class="blob-line-code js-file-line">    <span class="n">TH2</span><span class="o">::</span><span class="n">SetDefaultSumw2</span><span class="p">();</span></td>
      </tr>
      <tr>
        <td id="L120" class="blob-line-num js-line-number" data-line-number="120"></td>
        <td id="LC120" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L121" class="blob-line-num js-line-number" data-line-number="121"></td>
        <td id="LC121" class="blob-line-code js-file-line">    <span class="n">string</span> <span class="n">ZpT</span> <span class="o">=</span> <span class="s">&quot;p_{T}(Z) [GeV]&quot;</span><span class="p">,</span> <span class="n">Zrap</span> <span class="o">=</span> <span class="s">&quot;y(Z)&quot;</span><span class="p">,</span> <span class="n">Zeta</span> <span class="o">=</span> <span class="s">&quot;#eta(Z)&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L122" class="blob-line-num js-line-number" data-line-number="122"></td>
        <td id="LC122" class="blob-line-code js-file-line">    <span class="n">string</span> <span class="n">HT</span> <span class="o">=</span> <span class="s">&quot;H_{T}(jets) [GeV]&quot;</span><span class="p">,</span> <span class="n">Mjj</span> <span class="o">=</span> <span class="s">&quot;M_{j_{1}j_{2}} [GeV]&quot;</span><span class="p">,</span> <span class="n">jSpt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(j_{1}j_{2})&quot;</span><span class="p">,</span> <span class="n">jdPhi</span> <span class="o">=</span> <span class="s">&quot;#Delta#phi(j_{1}j_{2})&quot;</span><span class="p">,</span> <span class="n">jdEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(j_{1}j_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L123" class="blob-line-num js-line-number" data-line-number="123"></td>
        <td id="LC123" class="blob-line-code js-file-line">    <span class="n">string</span> <span class="n">Mll</span> <span class="o">=</span> <span class="s">&quot;M_{#mu#mu} [GeV]&quot;</span><span class="p">,</span> <span class="n">leta</span> <span class="o">=</span> <span class="s">&quot;#eta(#mu)&quot;</span><span class="p">,</span> <span class="n">lphi</span> <span class="o">=</span> <span class="s">&quot;#phi(#mu)&quot;</span><span class="p">,</span><span class="n">lpT</span> <span class="o">=</span> <span class="s">&quot;p_{T}(#mu) [GeV]&quot;</span><span class="p">,</span> <span class="n">ldPhi</span> <span class="o">=</span> <span class="s">&quot;#Delta#phi(#mu_{1}#mu_{2})&quot;</span><span class="p">,</span> <span class="n">ldEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(#mu_{1}#mu_{2})&quot;</span><span class="p">,</span> <span class="n">ldR</span> <span class="o">=</span> <span class="s">&quot;#DeltaR(#mu_{1}#mu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L124" class="blob-line-num js-line-number" data-line-number="124"></td>
        <td id="LC124" class="blob-line-code js-file-line">    <span class="n">string</span> <span class="n">lSpt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(#mu_{1}#mu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L125" class="blob-line-num js-line-number" data-line-number="125"></td>
        <td id="LC125" class="blob-line-code js-file-line">    <span class="n">string</span> <span class="n">Spt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(j_{1}j_{2}#mu_{1}#mu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L126" class="blob-line-num js-line-number" data-line-number="126"></td>
        <td id="LC126" class="blob-line-code js-file-line">    <span class="n">string</span> <span class="n">Sphi</span> <span class="o">=</span> <span class="s">&quot;Sphi(j_{1}j_{2}#mu_{1}#mu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L127" class="blob-line-num js-line-number" data-line-number="127"></td>
        <td id="LC127" class="blob-line-code js-file-line">    <span class="n">string</span> <span class="n">lJetdEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(#mu_{1}#mu_{2},j_{1})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L128" class="blob-line-num js-line-number" data-line-number="128"></td>
        <td id="LC128" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L129" class="blob-line-num js-line-number" data-line-number="129"></td>
        <td id="LC129" class="blob-line-code js-file-line">    <span class="kt">bool</span> <span class="n">doWJets</span> <span class="o">=</span> <span class="nb">false</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L130" class="blob-line-num js-line-number" data-line-number="130"></td>
        <td id="LC130" class="blob-line-code js-file-line">    <span class="k">if</span> <span class="p">(</span><span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;Electrons&quot;</span> <span class="o">||</span> <span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;DE&quot;</span> <span class="o">||</span> <span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;DE_&quot;</span><span class="p">)</span> <span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L131" class="blob-line-num js-line-number" data-line-number="131"></td>
        <td id="LC131" class="blob-line-code js-file-line">        <span class="n">Mll</span> <span class="o">=</span> <span class="s">&quot;M_{ee} [GeV]&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L132" class="blob-line-num js-line-number" data-line-number="132"></td>
        <td id="LC132" class="blob-line-code js-file-line">        <span class="n">leta</span> <span class="o">=</span> <span class="s">&quot;#eta(e)&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L133" class="blob-line-num js-line-number" data-line-number="133"></td>
        <td id="LC133" class="blob-line-code js-file-line">        <span class="n">lpT</span> <span class="o">=</span> <span class="s">&quot;p_{T}(e) [GeV]&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L134" class="blob-line-num js-line-number" data-line-number="134"></td>
        <td id="LC134" class="blob-line-code js-file-line">        <span class="n">ldPhi</span> <span class="o">=</span> <span class="s">&quot;#Delta#phi(e_{1}e_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L135" class="blob-line-num js-line-number" data-line-number="135"></td>
        <td id="LC135" class="blob-line-code js-file-line">        <span class="n">ldEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(e_{1}e_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L136" class="blob-line-num js-line-number" data-line-number="136"></td>
        <td id="LC136" class="blob-line-code js-file-line">        <span class="n">ldR</span> <span class="o">=</span> <span class="s">&quot;#DeltaR(e_{1}e_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L137" class="blob-line-num js-line-number" data-line-number="137"></td>
        <td id="LC137" class="blob-line-code js-file-line">        <span class="n">lSpt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(e_{1}e_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L138" class="blob-line-num js-line-number" data-line-number="138"></td>
        <td id="LC138" class="blob-line-code js-file-line">        <span class="n">Spt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(j_{1}j_{2}e_{1}e_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L139" class="blob-line-num js-line-number" data-line-number="139"></td>
        <td id="LC139" class="blob-line-code js-file-line">        <span class="n">Sphi</span> <span class="o">=</span> <span class="s">&quot;Sphi(j_{1}j_{2}e_{1}e_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L140" class="blob-line-num js-line-number" data-line-number="140"></td>
        <td id="LC140" class="blob-line-code js-file-line">        <span class="n">lJetdEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(e_{1}e_{2},j_{1})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L141" class="blob-line-num js-line-number" data-line-number="141"></td>
        <td id="LC141" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L142" class="blob-line-num js-line-number" data-line-number="142"></td>
        <td id="LC142" class="blob-line-code js-file-line">    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span> <span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;Electron&quot;</span> <span class="o">||</span> <span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;SE&quot;</span> <span class="o">||</span> <span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;SE_&quot;</span><span class="p">)</span> <span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L143" class="blob-line-num js-line-number" data-line-number="143"></td>
        <td id="LC143" class="blob-line-code js-file-line">        <span class="n">doWJets</span> <span class="o">=</span> <span class="nb">true</span> <span class="p">;</span> </td>
      </tr>
      <tr>
        <td id="L144" class="blob-line-num js-line-number" data-line-number="144"></td>
        <td id="LC144" class="blob-line-code js-file-line">        <span class="n">Mll</span> <span class="o">=</span> <span class="s">&quot;M_{e#nu} [GeV]&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L145" class="blob-line-num js-line-number" data-line-number="145"></td>
        <td id="LC145" class="blob-line-code js-file-line">        <span class="n">leta</span> <span class="o">=</span> <span class="s">&quot;#eta(e)&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L146" class="blob-line-num js-line-number" data-line-number="146"></td>
        <td id="LC146" class="blob-line-code js-file-line">        <span class="n">lpT</span> <span class="o">=</span> <span class="s">&quot;p_{T}(e) [GeV]&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L147" class="blob-line-num js-line-number" data-line-number="147"></td>
        <td id="LC147" class="blob-line-code js-file-line">        <span class="n">ldPhi</span> <span class="o">=</span> <span class="s">&quot;#Delta#phi(e_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L148" class="blob-line-num js-line-number" data-line-number="148"></td>
        <td id="LC148" class="blob-line-code js-file-line">        <span class="n">ldEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(e_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L149" class="blob-line-num js-line-number" data-line-number="149"></td>
        <td id="LC149" class="blob-line-code js-file-line">        <span class="n">ldR</span> <span class="o">=</span> <span class="s">&quot;#DeltaR(e_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L150" class="blob-line-num js-line-number" data-line-number="150"></td>
        <td id="LC150" class="blob-line-code js-file-line">        <span class="n">lSpt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(e_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L151" class="blob-line-num js-line-number" data-line-number="151"></td>
        <td id="LC151" class="blob-line-code js-file-line">        <span class="n">Spt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(j_{1}j_{2}e_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L152" class="blob-line-num js-line-number" data-line-number="152"></td>
        <td id="LC152" class="blob-line-code js-file-line">        <span class="n">Sphi</span> <span class="o">=</span> <span class="s">&quot;Sphi(j_{1}j_{2}e_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L153" class="blob-line-num js-line-number" data-line-number="153"></td>
        <td id="LC153" class="blob-line-code js-file-line">        <span class="n">lJetdEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(e,j_{1})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L154" class="blob-line-num js-line-number" data-line-number="154"></td>
        <td id="LC154" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L155" class="blob-line-num js-line-number" data-line-number="155"></td>
        <td id="LC155" class="blob-line-code js-file-line">    <span class="p">}</span> </td>
      </tr>
      <tr>
        <td id="L156" class="blob-line-num js-line-number" data-line-number="156"></td>
        <td id="LC156" class="blob-line-code js-file-line">    <span class="k">else</span> <span class="k">if</span> <span class="p">(</span> <span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;Muon&quot;</span> <span class="o">||</span> <span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;SMu&quot;</span> <span class="o">||</span> <span class="n">leptonFlavor</span> <span class="o">==</span> <span class="s">&quot;SMu_&quot;</span><span class="p">)</span> <span class="p">{</span></td>
      </tr>
      <tr>
        <td id="L157" class="blob-line-num js-line-number" data-line-number="157"></td>
        <td id="LC157" class="blob-line-code js-file-line">        <span class="n">doWJets</span> <span class="o">=</span> <span class="nb">true</span> <span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L158" class="blob-line-num js-line-number" data-line-number="158"></td>
        <td id="LC158" class="blob-line-code js-file-line">        <span class="n">Mll</span> <span class="o">=</span> <span class="s">&quot;M_{#mu#nu} [GeV]&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L159" class="blob-line-num js-line-number" data-line-number="159"></td>
        <td id="LC159" class="blob-line-code js-file-line">        <span class="n">ldPhi</span> <span class="o">=</span> <span class="s">&quot;#Delta#phi(#mu_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L160" class="blob-line-num js-line-number" data-line-number="160"></td>
        <td id="LC160" class="blob-line-code js-file-line">        <span class="n">ldEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(#mu_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L161" class="blob-line-num js-line-number" data-line-number="161"></td>
        <td id="LC161" class="blob-line-code js-file-line">        <span class="n">ldR</span> <span class="o">=</span> <span class="s">&quot;#DeltaR(e_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L162" class="blob-line-num js-line-number" data-line-number="162"></td>
        <td id="LC162" class="blob-line-code js-file-line">        <span class="n">lSpt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(#mu_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L163" class="blob-line-num js-line-number" data-line-number="163"></td>
        <td id="LC163" class="blob-line-code js-file-line">        <span class="n">Spt</span> <span class="o">=</span> <span class="s">&quot;#Delta_{pT}^{rel}(j_{1}j_{2}#mu_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L164" class="blob-line-num js-line-number" data-line-number="164"></td>
        <td id="LC164" class="blob-line-code js-file-line">        <span class="n">Sphi</span> <span class="o">=</span> <span class="s">&quot;Sphi(j_{1}j_{2}#mu_{1}#nu_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L165" class="blob-line-num js-line-number" data-line-number="165"></td>
        <td id="LC165" class="blob-line-code js-file-line">        <span class="n">lJetdEta</span> <span class="o">=</span> <span class="s">&quot;#Delta#eta(#mu,j_{1})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L166" class="blob-line-num js-line-number" data-line-number="166"></td>
        <td id="LC166" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L167" class="blob-line-num js-line-number" data-line-number="167"></td>
        <td id="LC167" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L168" class="blob-line-num js-line-number" data-line-number="168"></td>
        <td id="LC168" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L169" class="blob-line-num js-line-number" data-line-number="169"></td>
        <td id="LC169" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L170" class="blob-line-num js-line-number" data-line-number="170"></td>
        <td id="LC170" class="blob-line-code js-file-line">    <span class="cm">/*</span></td>
      </tr>
      <tr>
        <td id="L171" class="blob-line-num js-line-number" data-line-number="171"></td>
        <td id="LC171" class="blob-line-code js-file-line"><span class="cm">    /// for 7TeV</span></td>
      </tr>
      <tr>
        <td id="L172" class="blob-line-num js-line-number" data-line-number="172"></td>
        <td id="LC172" class="blob-line-code js-file-line"><span class="cm">    int nJetPt_Zinc1jet(12);</span></td>
      </tr>
      <tr>
        <td id="L173" class="blob-line-num js-line-number" data-line-number="173"></td>
        <td id="LC173" class="blob-line-code js-file-line"><span class="cm">    double jetPt_Zinc1jet[13] = {20, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};</span></td>
      </tr>
      <tr>
        <td id="L174" class="blob-line-num js-line-number" data-line-number="174"></td>
        <td id="LC174" class="blob-line-code js-file-line"><span class="cm">    int nJetPt_Zinc2jet(11);</span></td>
      </tr>
      <tr>
        <td id="L175" class="blob-line-num js-line-number" data-line-number="175"></td>
        <td id="LC175" class="blob-line-code js-file-line"><span class="cm">    double jetPt_Zinc2jet[12] = {20, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377};</span></td>
      </tr>
      <tr>
        <td id="L176" class="blob-line-num js-line-number" data-line-number="176"></td>
        <td id="LC176" class="blob-line-code js-file-line"><span class="cm">    int nJetPt_Zinc3jet(8);</span></td>
      </tr>
      <tr>
        <td id="L177" class="blob-line-num js-line-number" data-line-number="177"></td>
        <td id="LC177" class="blob-line-code js-file-line"><span class="cm">    double jetPt_Zinc3jet[9] =  {20, 30, 40, 52, 68, 88, 113, 144, 184};</span></td>
      </tr>
      <tr>
        <td id="L178" class="blob-line-num js-line-number" data-line-number="178"></td>
        <td id="LC178" class="blob-line-code js-file-line"><span class="cm">    int nJetPt_Zinc4jet(6);</span></td>
      </tr>
      <tr>
        <td id="L179" class="blob-line-num js-line-number" data-line-number="179"></td>
        <td id="LC179" class="blob-line-code js-file-line"><span class="cm">    double jetPt_Zinc4jet[7] =  {20, 30, 40, 52, 68, 88, 113};</span></td>
      </tr>
      <tr>
        <td id="L180" class="blob-line-num js-line-number" data-line-number="180"></td>
        <td id="LC180" class="blob-line-code js-file-line"><span class="cm">    int nJetPt_Zinc5jet(5);</span></td>
      </tr>
      <tr>
        <td id="L181" class="blob-line-num js-line-number" data-line-number="181"></td>
        <td id="LC181" class="blob-line-code js-file-line"><span class="cm">    double jetPt_Zinc5jet[6] =  {20, 30, 40, 52, 68, 88};</span></td>
      </tr>
      <tr>
        <td id="L182" class="blob-line-num js-line-number" data-line-number="182"></td>
        <td id="LC182" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L183" class="blob-line-num js-line-number" data-line-number="183"></td>
        <td id="LC183" class="blob-line-code js-file-line"><span class="cm">    // for extend to 10</span></td>
      </tr>
      <tr>
        <td id="L184" class="blob-line-num js-line-number" data-line-number="184"></td>
        <td id="LC184" class="blob-line-code js-file-line"><span class="cm">    //int nJetPt_Zinc1jet(14);</span></td>
      </tr>
      <tr>
        <td id="L185" class="blob-line-num js-line-number" data-line-number="185"></td>
        <td id="LC185" class="blob-line-code js-file-line"><span class="cm">    //double jetPt_Zinc1jet[15] = {10, 15, 20, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};</span></td>
      </tr>
      <tr>
        <td id="L186" class="blob-line-num js-line-number" data-line-number="186"></td>
        <td id="LC186" class="blob-line-code js-file-line"><span class="cm">    //int nJetPt_Zinc2jet(13);</span></td>
      </tr>
      <tr>
        <td id="L187" class="blob-line-num js-line-number" data-line-number="187"></td>
        <td id="LC187" class="blob-line-code js-file-line"><span class="cm">    //double jetPt_Zinc2jet[12] = {10, 15, 20, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377};</span></td>
      </tr>
      <tr>
        <td id="L188" class="blob-line-num js-line-number" data-line-number="188"></td>
        <td id="LC188" class="blob-line-code js-file-line"><span class="cm">    //int nJetPt_Zinc3jet(10);</span></td>
      </tr>
      <tr>
        <td id="L189" class="blob-line-num js-line-number" data-line-number="189"></td>
        <td id="LC189" class="blob-line-code js-file-line"><span class="cm">    //double jetPt_Zinc3jet[11] =  {10, 15, 20, 30, 40, 52, 68, 88, 113, 144, 184};</span></td>
      </tr>
      <tr>
        <td id="L190" class="blob-line-num js-line-number" data-line-number="190"></td>
        <td id="LC190" class="blob-line-code js-file-line"><span class="cm">    //int nJetPt_Zinc4jet(8);</span></td>
      </tr>
      <tr>
        <td id="L191" class="blob-line-num js-line-number" data-line-number="191"></td>
        <td id="LC191" class="blob-line-code js-file-line"><span class="cm">    //double jetPt_Zinc4jet[9] =  {10, 15, 20, 30, 40, 52, 68, 88, 113};</span></td>
      </tr>
      <tr>
        <td id="L192" class="blob-line-num js-line-number" data-line-number="192"></td>
        <td id="LC192" class="blob-line-code js-file-line"><span class="cm">    //int nJetPt_Zinc5jet(7);</span></td>
      </tr>
      <tr>
        <td id="L193" class="blob-line-num js-line-number" data-line-number="193"></td>
        <td id="LC193" class="blob-line-code js-file-line"><span class="cm">    //double jetPt_Zinc5jet[8] =  {10, 15, 20, 30, 40, 52, 68, 88};</span></td>
      </tr>
      <tr>
        <td id="L194" class="blob-line-num js-line-number" data-line-number="194"></td>
        <td id="LC194" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L195" class="blob-line-num js-line-number" data-line-number="195"></td>
        <td id="LC195" class="blob-line-code js-file-line"><span class="cm">    int nJetPtEta_Zinc1jet(9);</span></td>
      </tr>
      <tr>
        <td id="L196" class="blob-line-num js-line-number" data-line-number="196"></td>
        <td id="LC196" class="blob-line-code js-file-line"><span class="cm">    double jetPtEta_Zinc1jet[10] = {20, 30, 40, 52, 68, 88, 113, 144, 184, 480};</span></td>
      </tr>
      <tr>
        <td id="L197" class="blob-line-num js-line-number" data-line-number="197"></td>
        <td id="LC197" class="blob-line-code js-file-line"><span class="cm">    int nJetPtEta_Zinc2jet(8);</span></td>
      </tr>
      <tr>
        <td id="L198" class="blob-line-num js-line-number" data-line-number="198"></td>
        <td id="LC198" class="blob-line-code js-file-line"><span class="cm">    double jetPtEta_Zinc2jet[9]  = {20, 30, 40, 52, 68, 88, 113, 144, 377};</span></td>
      </tr>
      <tr>
        <td id="L199" class="blob-line-num js-line-number" data-line-number="199"></td>
        <td id="LC199" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L200" class="blob-line-num js-line-number" data-line-number="200"></td>
        <td id="LC200" class="blob-line-code js-file-line"><span class="cm">    int nJetHT_Zinc1jet(12);</span></td>
      </tr>
      <tr>
        <td id="L201" class="blob-line-num js-line-number" data-line-number="201"></td>
        <td id="LC201" class="blob-line-code js-file-line"><span class="cm">    double jetHT_Zinc1jet[13] = {20, 30, 45, 65, 91, 125, 170, 230, 306, 406, 536, 707, 932};</span></td>
      </tr>
      <tr>
        <td id="L202" class="blob-line-num js-line-number" data-line-number="202"></td>
        <td id="LC202" class="blob-line-code js-file-line"><span class="cm">    int nJetHT_Zinc2jet(12);</span></td>
      </tr>
      <tr>
        <td id="L203" class="blob-line-num js-line-number" data-line-number="203"></td>
        <td id="LC203" class="blob-line-code js-file-line"><span class="cm">    double jetHT_Zinc2jet[13] = {40, 60, 75, 95, 121, 155, 200, 260, 336, 436, 566, 737, 962};</span></td>
      </tr>
      <tr>
        <td id="L204" class="blob-line-num js-line-number" data-line-number="204"></td>
        <td id="LC204" class="blob-line-code js-file-line"><span class="cm">    int nJetHT_Zinc3jet(12);</span></td>
      </tr>
      <tr>
        <td id="L205" class="blob-line-num js-line-number" data-line-number="205"></td>
        <td id="LC205" class="blob-line-code js-file-line"><span class="cm">    double jetHT_Zinc3jet[13] = {60, 75, 90, 105, 125, 151, 185, 230, 290, 366, 466, 586, 767};</span></td>
      </tr>
      <tr>
        <td id="L206" class="blob-line-num js-line-number" data-line-number="206"></td>
        <td id="LC206" class="blob-line-code js-file-line"><span class="cm">    int nJetHT_Zinc4jet(11);</span></td>
      </tr>
      <tr>
        <td id="L207" class="blob-line-num js-line-number" data-line-number="207"></td>
        <td id="LC207" class="blob-line-code js-file-line"><span class="cm">    double jetHT_Zinc4jet[12] = {80, 100, 120, 140, 167, 203, 253, 320, 410, 530, 690, 910};</span></td>
      </tr>
      <tr>
        <td id="L208" class="blob-line-num js-line-number" data-line-number="208"></td>
        <td id="LC208" class="blob-line-code js-file-line"><span class="cm">    int nJetHT_Zinc5jet(9);</span></td>
      </tr>
      <tr>
        <td id="L209" class="blob-line-num js-line-number" data-line-number="209"></td>
        <td id="LC209" class="blob-line-code js-file-line"><span class="cm">    double jetHT_Zinc5jet[10] = {100, 125, 150, 180, 222, 282, 365, 485, 650, 880};</span></td>
      </tr>
      <tr>
        <td id="L210" class="blob-line-num js-line-number" data-line-number="210"></td>
        <td id="LC210" class="blob-line-code js-file-line"><span class="cm">    */</span></td>
      </tr>
      <tr>
        <td id="L211" class="blob-line-num js-line-number" data-line-number="211"></td>
        <td id="LC211" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L212" class="blob-line-num js-line-number" data-line-number="212"></td>
        <td id="LC212" class="blob-line-code js-file-line">    <span class="c1">/// for 8TeV</span></td>
      </tr>
      <tr>
        <td id="L213" class="blob-line-num js-line-number" data-line-number="213"></td>
        <td id="LC213" class="blob-line-code js-file-line">    <span class="cm">/*int nJetPt_Zinc1jet(11);</span></td>
      </tr>
      <tr>
        <td id="L214" class="blob-line-num js-line-number" data-line-number="214"></td>
        <td id="LC214" class="blob-line-code js-file-line"><span class="cm">      double jetPt_Zinc1jet[12] = {30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};</span></td>
      </tr>
      <tr>
        <td id="L215" class="blob-line-num js-line-number" data-line-number="215"></td>
        <td id="LC215" class="blob-line-code js-file-line"><span class="cm">      int nJetPt_Zinc2jet(10);</span></td>
      </tr>
      <tr>
        <td id="L216" class="blob-line-num js-line-number" data-line-number="216"></td>
        <td id="LC216" class="blob-line-code js-file-line"><span class="cm">      double jetPt_Zinc2jet[11] = {30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377};</span></td>
      </tr>
      <tr>
        <td id="L217" class="blob-line-num js-line-number" data-line-number="217"></td>
        <td id="LC217" class="blob-line-code js-file-line"><span class="cm">      int nJetPt_Zinc3jet(7);</span></td>
      </tr>
      <tr>
        <td id="L218" class="blob-line-num js-line-number" data-line-number="218"></td>
        <td id="LC218" class="blob-line-code js-file-line"><span class="cm">      double jetPt_Zinc3jet[8] =  {30, 40, 52, 68, 88, 113, 144, 184};</span></td>
      </tr>
      <tr>
        <td id="L219" class="blob-line-num js-line-number" data-line-number="219"></td>
        <td id="LC219" class="blob-line-code js-file-line"><span class="cm">      int nJetPt_Zinc4jet(5);</span></td>
      </tr>
      <tr>
        <td id="L220" class="blob-line-num js-line-number" data-line-number="220"></td>
        <td id="LC220" class="blob-line-code js-file-line"><span class="cm">      double jetPt_Zinc4jet[6] =  {30, 40, 52, 68, 88, 113};</span></td>
      </tr>
      <tr>
        <td id="L221" class="blob-line-num js-line-number" data-line-number="221"></td>
        <td id="LC221" class="blob-line-code js-file-line"><span class="cm">      int nJetPt_Zinc5jet(4);</span></td>
      </tr>
      <tr>
        <td id="L222" class="blob-line-num js-line-number" data-line-number="222"></td>
        <td id="LC222" class="blob-line-code js-file-line"><span class="cm">      double jetPt_Zinc5jet[5] =  {30, 40, 52, 68, 88};</span></td>
      </tr>
      <tr>
        <td id="L223" class="blob-line-num js-line-number" data-line-number="223"></td>
        <td id="LC223" class="blob-line-code js-file-line"><span class="cm">      */</span></td>
      </tr>
      <tr>
        <td id="L224" class="blob-line-num js-line-number" data-line-number="224"></td>
        <td id="LC224" class="blob-line-code js-file-line">    <span class="c1">// for extend to 20</span></td>
      </tr>
      <tr>
        <td id="L225" class="blob-line-num js-line-number" data-line-number="225"></td>
        <td id="LC225" class="blob-line-code js-file-line">    <span class="c1">//int nJetPt_Zinc1jet(13);</span></td>
      </tr>
      <tr>
        <td id="L226" class="blob-line-num js-line-number" data-line-number="226"></td>
        <td id="LC226" class="blob-line-code js-file-line">    <span class="c1">//double jetPt_Zinc1jet[14] = {20, 24, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};</span></td>
      </tr>
      <tr>
        <td id="L227" class="blob-line-num js-line-number" data-line-number="227"></td>
        <td id="LC227" class="blob-line-code js-file-line">    <span class="c1">//int nJetPt_Zinc2jet(12);</span></td>
      </tr>
      <tr>
        <td id="L228" class="blob-line-num js-line-number" data-line-number="228"></td>
        <td id="LC228" class="blob-line-code js-file-line">    <span class="c1">//double jetPt_Zinc2jet[13] = {20, 24, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377};</span></td>
      </tr>
      <tr>
        <td id="L229" class="blob-line-num js-line-number" data-line-number="229"></td>
        <td id="LC229" class="blob-line-code js-file-line">    <span class="c1">//int nJetPt_Zinc3jet(9);</span></td>
      </tr>
      <tr>
        <td id="L230" class="blob-line-num js-line-number" data-line-number="230"></td>
        <td id="LC230" class="blob-line-code js-file-line">    <span class="c1">//double jetPt_Zinc3jet[10] = {20, 24, 30, 40, 52, 68, 88, 113, 144, 184};</span></td>
      </tr>
      <tr>
        <td id="L231" class="blob-line-num js-line-number" data-line-number="231"></td>
        <td id="LC231" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L232" class="blob-line-num js-line-number" data-line-number="232"></td>
        <td id="LC232" class="blob-line-code js-file-line">    <span class="c1">//int nJetPt_Zinc1jet(13);</span></td>
      </tr>
      <tr>
        <td id="L233" class="blob-line-num js-line-number" data-line-number="233"></td>
        <td id="LC233" class="blob-line-code js-file-line">    <span class="c1">//double jetPt_Zinc1jet[14]   = {20, 24, 30, 40, 52, 68, 88, 113, 144, 184, 234, 297, 377, 480};</span></td>
      </tr>
      <tr>
        <td id="L234" class="blob-line-num js-line-number" data-line-number="234"></td>
        <td id="LC234" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="n">nJetPt_Zinc1jet</span><span class="p">(</span><span class="mi">14</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L235" class="blob-line-num js-line-number" data-line-number="235"></td>
        <td id="LC235" class="blob-line-code js-file-line">    <span class="n">vector</span><span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;</span> <span class="n">jetPt_Zinc1jet</span> <span class="o">=</span> <span class="n">makeVector</span><span class="p">(</span><span class="n">nJetPt_Zinc1jet</span><span class="p">,</span> <span class="mf">20.</span><span class="p">,</span> <span class="mf">24.</span><span class="p">,</span> <span class="mf">30.</span><span class="p">,</span> <span class="mf">40.</span><span class="p">,</span> <span class="mf">52.</span><span class="p">,</span> <span class="mf">68.</span><span class="p">,</span> <span class="mf">88.</span><span class="p">,</span> <span class="mf">113.</span><span class="p">,</span> <span class="mf">144.</span><span class="p">,</span> <span class="mf">184.</span><span class="p">,</span> <span class="mf">234.</span><span class="p">,</span> <span class="mf">297.</span><span class="p">,</span> <span class="mf">377.</span><span class="p">,</span> <span class="mf">480.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L236" class="blob-line-num js-line-number" data-line-number="236"></td>
        <td id="LC236" class="blob-line-code js-file-line">    <span class="c1">//int nJetPt_1_Zinc1jet(17);</span></td>
      </tr>
      <tr>
        <td id="L237" class="blob-line-num js-line-number" data-line-number="237"></td>
        <td id="LC237" class="blob-line-code js-file-line">    <span class="c1">//double jetPt_1_Zinc1jet[18] = {20, 24, 30, 39, 49, 62, 78, 96, 118, 150, 190, 240, 300, 370, 450, 540, 650, 1000};</span></td>
      </tr>
      <tr>
        <td id="L238" class="blob-line-num js-line-number" data-line-number="238"></td>
        <td id="LC238" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_1_Zinc1jet</span><span class="p">(</span><span class="mi">18</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L239" class="blob-line-num js-line-number" data-line-number="239"></td>
        <td id="LC239" class="blob-line-code js-file-line">    <span class="n">vector</span><span class="o">&lt;</span><span class="kt">double</span><span class="o">&gt;</span> <span class="n">jetPt_1_Zinc1jet</span> <span class="o">=</span> <span class="n">makeVector</span><span class="p">(</span><span class="n">nJetPt_1_Zinc1jet</span><span class="p">,</span> <span class="mf">20.</span><span class="p">,</span> <span class="mf">24.</span><span class="p">,</span> <span class="mf">30.</span><span class="p">,</span> <span class="mf">39.</span><span class="p">,</span> <span class="mf">49.</span><span class="p">,</span> <span class="mf">62.</span><span class="p">,</span> <span class="mf">78.</span><span class="p">,</span> <span class="mf">96.</span><span class="p">,</span> <span class="mf">118.</span><span class="p">,</span> <span class="mf">150.</span><span class="p">,</span> <span class="mf">190.</span><span class="p">,</span> <span class="mf">240.</span><span class="p">,</span> <span class="mf">300.</span><span class="p">,</span> <span class="mf">370.</span><span class="p">,</span> <span class="mf">450.</span><span class="p">,</span> <span class="mf">540.</span><span class="p">,</span> <span class="mf">650.</span><span class="p">,</span> <span class="mf">1000.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L240" class="blob-line-num js-line-number" data-line-number="240"></td>
        <td id="LC240" class="blob-line-code js-file-line">    <span class="n">insertVector</span><span class="p">(</span><span class="n">jetPt_1_Zinc1jet</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="mf">1300.</span><span class="p">,</span> <span class="mf">1500.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L241" class="blob-line-num js-line-number" data-line-number="241"></td>
        <td id="LC241" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_2_Zinc1jet</span><span class="p">(</span><span class="mi">22</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L242" class="blob-line-num js-line-number" data-line-number="242"></td>
        <td id="LC242" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_2_Zinc1jet</span><span class="p">[</span><span class="mi">23</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">72</span><span class="p">,</span> <span class="mi">85</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">117</span><span class="p">,</span> <span class="mi">136</span><span class="p">,</span> <span class="mi">157</span><span class="p">,</span> <span class="mi">187</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">258</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">350</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">590</span><span class="p">,</span> <span class="mi">700</span><span class="p">,</span> <span class="mi">1000</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L243" class="blob-line-num js-line-number" data-line-number="243"></td>
        <td id="LC243" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_3_Zinc1jet</span><span class="p">(</span><span class="mi">22</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L244" class="blob-line-num js-line-number" data-line-number="244"></td>
        <td id="LC244" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_3_Zinc1jet</span><span class="p">[</span><span class="mi">23</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">37</span><span class="p">,</span> <span class="mi">45</span><span class="p">,</span> <span class="mi">56</span><span class="p">,</span> <span class="mi">70</span><span class="p">,</span> <span class="mi">85</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">117</span><span class="p">,</span> <span class="mi">136</span><span class="p">,</span> <span class="mi">157</span><span class="p">,</span> <span class="mi">187</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">258</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">350</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">590</span><span class="p">,</span> <span class="mi">700</span><span class="p">,</span> <span class="mi">1000</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L245" class="blob-line-num js-line-number" data-line-number="245"></td>
        <td id="LC245" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_4_Zinc1jet</span><span class="p">(</span><span class="mi">26</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L246" class="blob-line-num js-line-number" data-line-number="246"></td>
        <td id="LC246" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_4_Zinc1jet</span><span class="p">[</span><span class="mi">27</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">35</span><span class="p">,</span> <span class="mi">40</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">70</span><span class="p">,</span> <span class="mi">80</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">140</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">250</span><span class="p">,</span> <span class="mi">280</span><span class="p">,</span> <span class="mi">310</span><span class="p">,</span> <span class="mi">340</span><span class="p">,</span> <span class="mi">370</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">550</span><span class="p">,</span> <span class="mi">700</span><span class="p">,</span> <span class="mi">1000</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L247" class="blob-line-num js-line-number" data-line-number="247"></td>
        <td id="LC247" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L248" class="blob-line-num js-line-number" data-line-number="248"></td>
        <td id="LC248" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_Zinc2jet</span><span class="p">(</span><span class="mi">16</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L249" class="blob-line-num js-line-number" data-line-number="249"></td>
        <td id="LC249" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_Zinc2jet</span><span class="p">[</span><span class="mi">17</span><span class="p">]</span>   <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">72</span><span class="p">,</span> <span class="mi">85</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">235</span><span class="p">,</span> <span class="mi">285</span><span class="p">,</span> <span class="mi">330</span><span class="p">,</span> <span class="mi">390</span><span class="p">,</span> <span class="mi">470</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L250" class="blob-line-num js-line-number" data-line-number="250"></td>
        <td id="LC250" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_1_Zinc2jet</span><span class="p">(</span><span class="mi">16</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L251" class="blob-line-num js-line-number" data-line-number="251"></td>
        <td id="LC251" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_1_Zinc2jet</span><span class="p">[</span><span class="mi">17</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">62</span><span class="p">,</span> <span class="mi">78</span><span class="p">,</span> <span class="mi">96</span><span class="p">,</span> <span class="mi">118</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">240</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">370</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">540</span><span class="p">,</span> <span class="mi">800</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L252" class="blob-line-num js-line-number" data-line-number="252"></td>
        <td id="LC252" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_2_Zinc2jet</span><span class="p">(</span><span class="mi">21</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L253" class="blob-line-num js-line-number" data-line-number="253"></td>
        <td id="LC253" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_2_Zinc2jet</span><span class="p">[</span><span class="mi">22</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">72</span><span class="p">,</span> <span class="mi">85</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">117</span><span class="p">,</span> <span class="mi">136</span><span class="p">,</span> <span class="mi">157</span><span class="p">,</span> <span class="mi">187</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">258</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">350</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">590</span><span class="p">,</span> <span class="mi">800</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L254" class="blob-line-num js-line-number" data-line-number="254"></td>
        <td id="LC254" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_3_Zinc2jet</span><span class="p">(</span><span class="mi">20</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L255" class="blob-line-num js-line-number" data-line-number="255"></td>
        <td id="LC255" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_3_Zinc2jet</span><span class="p">[</span><span class="mi">21</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">37</span><span class="p">,</span> <span class="mi">45</span><span class="p">,</span> <span class="mi">56</span><span class="p">,</span> <span class="mi">70</span><span class="p">,</span> <span class="mi">85</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">117</span><span class="p">,</span> <span class="mi">136</span><span class="p">,</span> <span class="mi">157</span><span class="p">,</span> <span class="mi">187</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">258</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">350</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">800</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L256" class="blob-line-num js-line-number" data-line-number="256"></td>
        <td id="LC256" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_4_Zinc2jet</span><span class="p">(</span><span class="mi">22</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L257" class="blob-line-num js-line-number" data-line-number="257"></td>
        <td id="LC257" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_4_Zinc2jet</span><span class="p">[</span><span class="mi">23</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">35</span><span class="p">,</span> <span class="mi">40</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">70</span><span class="p">,</span> <span class="mi">80</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">140</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">250</span><span class="p">,</span> <span class="mi">280</span><span class="p">,</span> <span class="mi">310</span><span class="p">,</span> <span class="mi">340</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">550</span><span class="p">,</span> <span class="mi">700</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L258" class="blob-line-num js-line-number" data-line-number="258"></td>
        <td id="LC258" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L259" class="blob-line-num js-line-number" data-line-number="259"></td>
        <td id="LC259" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_Zinc3jet</span><span class="p">(</span><span class="mi">11</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L260" class="blob-line-num js-line-number" data-line-number="260"></td>
        <td id="LC260" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_Zinc3jet</span><span class="p">[</span><span class="mi">12</span><span class="p">]</span>   <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">62</span><span class="p">,</span> <span class="mi">78</span><span class="p">,</span> <span class="mi">105</span><span class="p">,</span> <span class="mi">142</span><span class="p">,</span> <span class="mi">185</span><span class="p">,</span> <span class="mi">235</span><span class="p">,</span> <span class="mi">300</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L261" class="blob-line-num js-line-number" data-line-number="261"></td>
        <td id="LC261" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_1_Zinc3jet</span><span class="p">(</span><span class="mi">15</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L262" class="blob-line-num js-line-number" data-line-number="262"></td>
        <td id="LC262" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_1_Zinc3jet</span><span class="p">[</span><span class="mi">16</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">62</span><span class="p">,</span> <span class="mi">78</span><span class="p">,</span> <span class="mi">96</span><span class="p">,</span> <span class="mi">118</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">240</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">370</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">700</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L263" class="blob-line-num js-line-number" data-line-number="263"></td>
        <td id="LC263" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_2_Zinc3jet</span><span class="p">(</span><span class="mi">19</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L264" class="blob-line-num js-line-number" data-line-number="264"></td>
        <td id="LC264" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_2_Zinc3jet</span><span class="p">[</span><span class="mi">20</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">72</span><span class="p">,</span> <span class="mi">85</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">117</span><span class="p">,</span> <span class="mi">136</span><span class="p">,</span> <span class="mi">157</span><span class="p">,</span> <span class="mi">187</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">258</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">350</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">700</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L265" class="blob-line-num js-line-number" data-line-number="265"></td>
        <td id="LC265" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_3_Zinc3jet</span><span class="p">(</span><span class="mi">19</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L266" class="blob-line-num js-line-number" data-line-number="266"></td>
        <td id="LC266" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_3_Zinc3jet</span><span class="p">[</span><span class="mi">20</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">37</span><span class="p">,</span> <span class="mi">45</span><span class="p">,</span> <span class="mi">56</span><span class="p">,</span> <span class="mi">70</span><span class="p">,</span> <span class="mi">85</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">117</span><span class="p">,</span> <span class="mi">136</span><span class="p">,</span> <span class="mi">157</span><span class="p">,</span> <span class="mi">187</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">258</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">350</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">700</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L267" class="blob-line-num js-line-number" data-line-number="267"></td>
        <td id="LC267" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_4_Zinc3jet</span><span class="p">(</span><span class="mi">16</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L268" class="blob-line-num js-line-number" data-line-number="268"></td>
        <td id="LC268" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_4_Zinc3jet</span><span class="p">[</span><span class="mi">17</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">35</span><span class="p">,</span> <span class="mi">40</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">70</span><span class="p">,</span> <span class="mi">80</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">140</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">250</span><span class="p">,</span> <span class="mi">500</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L269" class="blob-line-num js-line-number" data-line-number="269"></td>
        <td id="LC269" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L270" class="blob-line-num js-line-number" data-line-number="270"></td>
        <td id="LC270" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_Zinc4jet</span><span class="p">(</span><span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L271" class="blob-line-num js-line-number" data-line-number="271"></td>
        <td id="LC271" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_Zinc4jet</span><span class="p">[</span><span class="mi">9</span><span class="p">]</span>   <span class="o">=</span> <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">62</span><span class="p">,</span> <span class="mi">78</span><span class="p">,</span> <span class="mi">96</span><span class="p">,</span> <span class="mi">150</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L272" class="blob-line-num js-line-number" data-line-number="272"></td>
        <td id="LC272" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L273" class="blob-line-num js-line-number" data-line-number="273"></td>
        <td id="LC273" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPt_Zinc5jet</span><span class="p">(</span><span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L274" class="blob-line-num js-line-number" data-line-number="274"></td>
        <td id="LC274" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPt_Zinc5jet</span><span class="p">[</span><span class="mi">7</span><span class="p">]</span> <span class="o">=</span>  <span class="p">{</span><span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">62</span><span class="p">,</span> <span class="mi">100</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L275" class="blob-line-num js-line-number" data-line-number="275"></td>
        <td id="LC275" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L276" class="blob-line-num js-line-number" data-line-number="276"></td>
        <td id="LC276" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPtEta_Zinc1jet</span><span class="p">(</span><span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L277" class="blob-line-num js-line-number" data-line-number="277"></td>
        <td id="LC277" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPtEta_Zinc1jet</span><span class="p">[</span><span class="mi">9</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">30</span><span class="p">,</span> <span class="mi">40</span><span class="p">,</span> <span class="mi">52</span><span class="p">,</span> <span class="mi">68</span><span class="p">,</span> <span class="mi">88</span><span class="p">,</span> <span class="mi">113</span><span class="p">,</span> <span class="mi">144</span><span class="p">,</span> <span class="mi">184</span><span class="p">,</span> <span class="mi">480</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L278" class="blob-line-num js-line-number" data-line-number="278"></td>
        <td id="LC278" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L279" class="blob-line-num js-line-number" data-line-number="279"></td>
        <td id="LC279" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPtEta_Zinc2jet</span><span class="p">(</span><span class="mi">7</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L280" class="blob-line-num js-line-number" data-line-number="280"></td>
        <td id="LC280" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPtEta_Zinc2jet</span><span class="p">[</span><span class="mi">8</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">30</span><span class="p">,</span> <span class="mi">40</span><span class="p">,</span> <span class="mi">52</span><span class="p">,</span> <span class="mi">68</span><span class="p">,</span> <span class="mi">88</span><span class="p">,</span> <span class="mi">113</span><span class="p">,</span> <span class="mi">144</span><span class="p">,</span> <span class="mi">377</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L281" class="blob-line-num js-line-number" data-line-number="281"></td>
        <td id="LC281" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L282" class="blob-line-num js-line-number" data-line-number="282"></td>
        <td id="LC282" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_Zinc1jet</span><span class="p">(</span><span class="mi">11</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L283" class="blob-line-num js-line-number" data-line-number="283"></td>
        <td id="LC283" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_Zinc1jet</span><span class="p">[</span><span class="mi">12</span><span class="p">]</span>   <span class="o">=</span> <span class="p">{</span><span class="mi">30</span><span class="p">,</span> <span class="mi">45</span><span class="p">,</span> <span class="mi">65</span><span class="p">,</span> <span class="mi">91</span><span class="p">,</span> <span class="mi">125</span><span class="p">,</span> <span class="mi">170</span><span class="p">,</span> <span class="mi">230</span><span class="p">,</span> <span class="mi">306</span><span class="p">,</span> <span class="mi">406</span><span class="p">,</span> <span class="mi">536</span><span class="p">,</span> <span class="mi">707</span><span class="p">,</span> <span class="mi">932</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L284" class="blob-line-num js-line-number" data-line-number="284"></td>
        <td id="LC284" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_1_Zinc1jet</span><span class="p">(</span><span class="mi">17</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L285" class="blob-line-num js-line-number" data-line-number="285"></td>
        <td id="LC285" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_1_Zinc1jet</span><span class="p">[</span><span class="mi">18</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">30</span><span class="p">,</span> <span class="mi">39</span><span class="p">,</span> <span class="mi">49</span><span class="p">,</span> <span class="mi">62</span><span class="p">,</span> <span class="mi">78</span><span class="p">,</span> <span class="mi">96</span><span class="p">,</span> <span class="mi">118</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">240</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">370</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">540</span><span class="p">,</span> <span class="mi">650</span><span class="p">,</span> <span class="mi">800</span><span class="p">,</span> <span class="mi">1000</span><span class="p">,</span> <span class="mi">1500</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L286" class="blob-line-num js-line-number" data-line-number="286"></td>
        <td id="LC286" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_2_Zinc1jet</span><span class="p">(</span><span class="mi">14</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L287" class="blob-line-num js-line-number" data-line-number="287"></td>
        <td id="LC287" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_2_Zinc1jet</span><span class="p">[</span><span class="mi">15</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">30</span><span class="p">,</span> <span class="mi">40</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">90</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">210</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">330</span><span class="p">,</span> <span class="mi">410</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">620</span><span class="p">,</span> <span class="mi">750</span><span class="p">,</span> <span class="mi">900</span><span class="p">,</span> <span class="mi">1200</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L288" class="blob-line-num js-line-number" data-line-number="288"></td>
        <td id="LC288" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_3_Zinc1jet</span><span class="p">(</span><span class="mi">11</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L289" class="blob-line-num js-line-number" data-line-number="289"></td>
        <td id="LC289" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_3_Zinc1jet</span><span class="p">[</span><span class="mi">12</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">30</span><span class="p">,</span> <span class="mi">45</span><span class="p">,</span> <span class="mi">65</span><span class="p">,</span> <span class="mi">91</span><span class="p">,</span> <span class="mi">125</span><span class="p">,</span> <span class="mi">170</span><span class="p">,</span> <span class="mi">230</span><span class="p">,</span> <span class="mi">306</span><span class="p">,</span> <span class="mi">406</span><span class="p">,</span> <span class="mi">536</span><span class="p">,</span> <span class="mi">707</span><span class="p">,</span> <span class="mi">932</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L290" class="blob-line-num js-line-number" data-line-number="290"></td>
        <td id="LC290" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_4_Zinc1jet</span><span class="p">(</span><span class="mi">31</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L291" class="blob-line-num js-line-number" data-line-number="291"></td>
        <td id="LC291" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_4_Zinc1jet</span><span class="p">[</span><span class="mi">32</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">30</span><span class="p">,</span> <span class="mi">40</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">70</span><span class="p">,</span> <span class="mi">80</span><span class="p">,</span> <span class="mi">90</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">110</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">130</span><span class="p">,</span> <span class="mi">140</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">170</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">240</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">280</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">320</span><span class="p">,</span> <span class="mi">340</span><span class="p">,</span> <span class="mi">360</span><span class="p">,</span> <span class="mi">380</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">650</span><span class="p">,</span> <span class="mi">1000</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L292" class="blob-line-num js-line-number" data-line-number="292"></td>
        <td id="LC292" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L293" class="blob-line-num js-line-number" data-line-number="293"></td>
        <td id="LC293" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_Zinc2jet</span><span class="p">(</span><span class="mi">11</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L294" class="blob-line-num js-line-number" data-line-number="294"></td>
        <td id="LC294" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_Zinc2jet</span><span class="p">[</span><span class="mi">12</span><span class="p">]</span>   <span class="o">=</span> <span class="p">{</span><span class="mi">60</span><span class="p">,</span> <span class="mi">75</span><span class="p">,</span> <span class="mi">95</span><span class="p">,</span> <span class="mi">121</span><span class="p">,</span> <span class="mi">155</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">336</span><span class="p">,</span> <span class="mi">436</span><span class="p">,</span> <span class="mi">566</span><span class="p">,</span> <span class="mi">737</span><span class="p">,</span> <span class="mi">962</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L295" class="blob-line-num js-line-number" data-line-number="295"></td>
        <td id="LC295" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_1_Zinc2jet</span><span class="p">(</span><span class="mi">13</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L296" class="blob-line-num js-line-number" data-line-number="296"></td>
        <td id="LC296" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_1_Zinc2jet</span><span class="p">[</span><span class="mi">14</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">60</span><span class="p">,</span> <span class="mi">78</span><span class="p">,</span> <span class="mi">96</span><span class="p">,</span> <span class="mi">118</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">240</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">370</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">540</span><span class="p">,</span> <span class="mi">650</span><span class="p">,</span> <span class="mi">800</span><span class="p">,</span> <span class="mi">1200</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L297" class="blob-line-num js-line-number" data-line-number="297"></td>
        <td id="LC297" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_2_Zinc2jet</span><span class="p">(</span><span class="mi">12</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L298" class="blob-line-num js-line-number" data-line-number="298"></td>
        <td id="LC298" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_2_Zinc2jet</span><span class="p">[</span><span class="mi">13</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">60</span><span class="p">,</span> <span class="mi">90</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">210</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">330</span><span class="p">,</span> <span class="mi">410</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">620</span><span class="p">,</span> <span class="mi">750</span><span class="p">,</span> <span class="mi">900</span><span class="p">,</span> <span class="mi">1200</span> <span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L299" class="blob-line-num js-line-number" data-line-number="299"></td>
        <td id="LC299" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_3_Zinc2jet</span><span class="p">(</span><span class="mi">9</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L300" class="blob-line-num js-line-number" data-line-number="300"></td>
        <td id="LC300" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_3_Zinc2jet</span><span class="p">[</span><span class="mi">10</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">60</span><span class="p">,</span> <span class="mi">91</span><span class="p">,</span> <span class="mi">125</span><span class="p">,</span> <span class="mi">170</span><span class="p">,</span> <span class="mi">230</span><span class="p">,</span> <span class="mi">306</span><span class="p">,</span> <span class="mi">406</span><span class="p">,</span> <span class="mi">536</span><span class="p">,</span> <span class="mi">707</span><span class="p">,</span> <span class="mi">932</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L301" class="blob-line-num js-line-number" data-line-number="301"></td>
        <td id="LC301" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_4_Zinc2jet</span><span class="p">(</span><span class="mi">28</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L302" class="blob-line-num js-line-number" data-line-number="302"></td>
        <td id="LC302" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_4_Zinc2jet</span><span class="p">[</span><span class="mi">29</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">60</span><span class="p">,</span> <span class="mi">70</span><span class="p">,</span> <span class="mi">80</span><span class="p">,</span> <span class="mi">90</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">110</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">130</span><span class="p">,</span> <span class="mi">140</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">170</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">240</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">280</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">320</span><span class="p">,</span> <span class="mi">340</span><span class="p">,</span> <span class="mi">360</span><span class="p">,</span> <span class="mi">380</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">650</span><span class="p">,</span> <span class="mi">1000</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L303" class="blob-line-num js-line-number" data-line-number="303"></td>
        <td id="LC303" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L304" class="blob-line-num js-line-number" data-line-number="304"></td>
        <td id="LC304" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_Zinc3jet</span><span class="p">(</span><span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L305" class="blob-line-num js-line-number" data-line-number="305"></td>
        <td id="LC305" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_Zinc3jet</span><span class="p">[</span><span class="mi">11</span><span class="p">]</span>   <span class="o">=</span> <span class="p">{</span><span class="mi">90</span><span class="p">,</span> <span class="mi">105</span><span class="p">,</span> <span class="mi">125</span><span class="p">,</span> <span class="mi">151</span><span class="p">,</span> <span class="mi">185</span><span class="p">,</span> <span class="mi">230</span><span class="p">,</span> <span class="mi">290</span><span class="p">,</span> <span class="mi">366</span><span class="p">,</span> <span class="mi">466</span><span class="p">,</span> <span class="mi">586</span><span class="p">,</span> <span class="mi">767</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L306" class="blob-line-num js-line-number" data-line-number="306"></td>
        <td id="LC306" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_1_Zinc3jet</span><span class="p">(</span><span class="mi">11</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L307" class="blob-line-num js-line-number" data-line-number="307"></td>
        <td id="LC307" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_1_Zinc3jet</span><span class="p">[</span><span class="mi">12</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">90</span><span class="p">,</span> <span class="mi">118</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">240</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">370</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">540</span><span class="p">,</span> <span class="mi">650</span><span class="p">,</span> <span class="mi">800</span><span class="p">,</span> <span class="mi">1200</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L308" class="blob-line-num js-line-number" data-line-number="308"></td>
        <td id="LC308" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_2_Zinc3jet</span><span class="p">(</span><span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L309" class="blob-line-num js-line-number" data-line-number="309"></td>
        <td id="LC309" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_2_Zinc3jet</span><span class="p">[</span><span class="mi">11</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">90</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">210</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">330</span><span class="p">,</span> <span class="mi">410</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">620</span><span class="p">,</span> <span class="mi">750</span><span class="p">,</span> <span class="mi">900</span> <span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L310" class="blob-line-num js-line-number" data-line-number="310"></td>
        <td id="LC310" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_3_Zinc3jet</span><span class="p">(</span><span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L311" class="blob-line-num js-line-number" data-line-number="311"></td>
        <td id="LC311" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_3_Zinc3jet</span><span class="p">[</span><span class="mi">9</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">90</span><span class="p">,</span> <span class="mi">125</span><span class="p">,</span> <span class="mi">170</span><span class="p">,</span> <span class="mi">230</span><span class="p">,</span> <span class="mi">306</span><span class="p">,</span> <span class="mi">406</span><span class="p">,</span> <span class="mi">536</span><span class="p">,</span> <span class="mi">707</span><span class="p">,</span> <span class="mi">932</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L312" class="blob-line-num js-line-number" data-line-number="312"></td>
        <td id="LC312" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_4_Zinc3jet</span><span class="p">(</span><span class="mi">25</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L313" class="blob-line-num js-line-number" data-line-number="313"></td>
        <td id="LC313" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_4_Zinc3jet</span><span class="p">[</span><span class="mi">26</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">90</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">110</span><span class="p">,</span> <span class="mi">120</span><span class="p">,</span> <span class="mi">130</span><span class="p">,</span> <span class="mi">140</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="mi">160</span><span class="p">,</span> <span class="mi">170</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">190</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">220</span><span class="p">,</span> <span class="mi">240</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">280</span><span class="p">,</span> <span class="mi">300</span><span class="p">,</span> <span class="mi">320</span><span class="p">,</span> <span class="mi">340</span><span class="p">,</span> <span class="mi">360</span><span class="p">,</span> <span class="mi">380</span><span class="p">,</span> <span class="mi">400</span><span class="p">,</span> <span class="mi">450</span><span class="p">,</span> <span class="mi">500</span><span class="p">,</span> <span class="mi">650</span><span class="p">,</span> <span class="mi">1000</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L314" class="blob-line-num js-line-number" data-line-number="314"></td>
        <td id="LC314" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L315" class="blob-line-num js-line-number" data-line-number="315"></td>
        <td id="LC315" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_Zinc4jet</span><span class="p">(</span><span class="mi">9</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L316" class="blob-line-num js-line-number" data-line-number="316"></td>
        <td id="LC316" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_Zinc4jet</span><span class="p">[</span><span class="mi">10</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">120</span><span class="p">,</span> <span class="mi">140</span><span class="p">,</span> <span class="mi">167</span><span class="p">,</span> <span class="mi">203</span><span class="p">,</span> <span class="mi">253</span><span class="p">,</span> <span class="mi">320</span><span class="p">,</span> <span class="mi">410</span><span class="p">,</span> <span class="mi">530</span><span class="p">,</span> <span class="mi">690</span><span class="p">,</span> <span class="mi">910</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L317" class="blob-line-num js-line-number" data-line-number="317"></td>
        <td id="LC317" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L318" class="blob-line-num js-line-number" data-line-number="318"></td>
        <td id="LC318" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHT_Zinc5jet</span><span class="p">(</span><span class="mi">7</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L319" class="blob-line-num js-line-number" data-line-number="319"></td>
        <td id="LC319" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHT_Zinc5jet</span><span class="p">[</span><span class="mi">8</span><span class="p">]</span> <span class="o">=</span>  <span class="p">{</span><span class="mi">150</span><span class="p">,</span> <span class="mi">180</span><span class="p">,</span> <span class="mi">222</span><span class="p">,</span> <span class="mi">282</span><span class="p">,</span> <span class="mi">365</span><span class="p">,</span> <span class="mi">485</span><span class="p">,</span> <span class="mi">650</span><span class="p">,</span> <span class="mi">880</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L320" class="blob-line-num js-line-number" data-line-number="320"></td>
        <td id="LC320" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L321" class="blob-line-num js-line-number" data-line-number="321"></td>
        <td id="LC321" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L322" class="blob-line-num js-line-number" data-line-number="322"></td>
        <td id="LC322" class="blob-line-code js-file-line">    <span class="n">NumberPFcandidates</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;NumberPFcandidates&quot;</span><span class="p">,</span>                  <span class="s">&quot;NumberPFcandidates&quot;</span><span class="p">,</span>           <span class="s">&quot;Number of lepton PF candidates&quot;</span><span class="p">,</span>    <span class="mi">20</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">19.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L323" class="blob-line-num js-line-number" data-line-number="323"></td>
        <td id="LC323" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L324" class="blob-line-num js-line-number" data-line-number="324"></td>
        <td id="LC324" class="blob-line-code js-file-line">    <span class="n">ZMass_lowDeltaR</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_lowDeltaR&quot;</span><span class="p">,</span>                     <span class="s">&quot;ZMass_lowDeltaR&quot;</span><span class="p">,</span>                             <span class="n">Mll</span><span class="p">,</span>    <span class="mi">120</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">169</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L325" class="blob-line-num js-line-number" data-line-number="325"></td>
        <td id="LC325" class="blob-line-code js-file-line">    <span class="n">AllPassLepID</span>			      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllPassLepID&quot;</span><span class="p">,</span>                        <span class="s">&quot;Lepton pair ID for all passing leptons&quot;</span><span class="p">,</span>    <span class="s">&quot;leptonPairID&quot;</span> <span class="p">,</span>    <span class="mi">54</span><span class="p">,</span> <span class="o">-</span><span class="mf">26.5</span><span class="p">,</span> <span class="mf">26.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L326" class="blob-line-num js-line-number" data-line-number="326"></td>
        <td id="LC326" class="blob-line-code js-file-line">    <span class="n">AllPassWithMassCutLepID</span>	      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllPassWithMassCutLepID&quot;</span><span class="p">,</span>                        <span class="s">&quot;Lepton pair ID for leptons + mass cut&quot;</span><span class="p">,</span>    <span class="s">&quot;leptonPairID&quot;</span> <span class="p">,</span>    <span class="mi">54</span><span class="p">,</span> <span class="o">-</span><span class="mf">26.5</span><span class="p">,</span> <span class="mf">26.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L327" class="blob-line-num js-line-number" data-line-number="327"></td>
        <td id="LC327" class="blob-line-code js-file-line">    <span class="n">AllPassWithMassCutLepIDCharge</span>	      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllPassWithMassCutLepIDCharge&quot;</span><span class="p">,</span>                        <span class="s">&quot;Lepton pair ID, charge for leptons + mass cut&quot;</span><span class="p">,</span>    <span class="s">&quot;leptonPairID&quot;</span> <span class="p">,</span>    <span class="mi">54</span><span class="p">,</span> <span class="o">-</span><span class="mf">26.5</span><span class="p">,</span> <span class="mf">26.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L328" class="blob-line-num js-line-number" data-line-number="328"></td>
        <td id="LC328" class="blob-line-code js-file-line">    <span class="n">ZMassAllPassLep</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMassAllPassLep&quot;</span><span class="p">,</span>                     <span class="s">&quot;Z Invariant Mass for all passing leptons&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">240</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">480</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L329" class="blob-line-num js-line-number" data-line-number="329"></td>
        <td id="LC329" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L330" class="blob-line-num js-line-number" data-line-number="330"></td>
        <td id="LC330" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L331" class="blob-line-num js-line-number" data-line-number="331"></td>
        <td id="LC331" class="blob-line-code js-file-line">    <span class="n">ZMass_Zinc0jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zinc0jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 0)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L332" class="blob-line-num js-line-number" data-line-number="332"></td>
        <td id="LC332" class="blob-line-code js-file-line">    <span class="n">ZMass_Zinc1jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zinc1jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 1)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L333" class="blob-line-num js-line-number" data-line-number="333"></td>
        <td id="LC333" class="blob-line-code js-file-line">    <span class="n">ZMass_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zinc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L334" class="blob-line-num js-line-number" data-line-number="334"></td>
        <td id="LC334" class="blob-line-code js-file-line">    <span class="n">ZMass_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zinc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 3)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L335" class="blob-line-num js-line-number" data-line-number="335"></td>
        <td id="LC335" class="blob-line-code js-file-line">    <span class="n">ZMass_Zinc4jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zinc4jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 4)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L336" class="blob-line-num js-line-number" data-line-number="336"></td>
        <td id="LC336" class="blob-line-code js-file-line">    <span class="n">ZMass_Zinc5jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zinc5jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 5)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L337" class="blob-line-num js-line-number" data-line-number="337"></td>
        <td id="LC337" class="blob-line-code js-file-line">    <span class="n">ZMass_Zinc6jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zinc6jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 6)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L338" class="blob-line-num js-line-number" data-line-number="338"></td>
        <td id="LC338" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L339" class="blob-line-num js-line-number" data-line-number="339"></td>
        <td id="LC339" class="blob-line-code js-file-line">    <span class="n">genZMass_Zinc0jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZMass_Zinc0jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 0)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L340" class="blob-line-num js-line-number" data-line-number="340"></td>
        <td id="LC340" class="blob-line-code js-file-line">    <span class="n">genZMass_Zinc1jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZMass_Zinc1jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 1)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L341" class="blob-line-num js-line-number" data-line-number="341"></td>
        <td id="LC341" class="blob-line-code js-file-line">    <span class="n">genZMass_Zinc2jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZMass_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L342" class="blob-line-num js-line-number" data-line-number="342"></td>
        <td id="LC342" class="blob-line-code js-file-line">    <span class="n">genZMass_Zinc3jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZMass_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 3)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L343" class="blob-line-num js-line-number" data-line-number="343"></td>
        <td id="LC343" class="blob-line-code js-file-line">    <span class="n">genZMass_Zinc4jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZMass_Zinc4jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 4)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L344" class="blob-line-num js-line-number" data-line-number="344"></td>
        <td id="LC344" class="blob-line-code js-file-line">    <span class="n">genZMass_Zinc5jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZMass_Zinc5jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 5)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L345" class="blob-line-num js-line-number" data-line-number="345"></td>
        <td id="LC345" class="blob-line-code js-file-line">    <span class="n">genZMass_Zinc6jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZMass_Zinc6jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Z Invariant Mass (N_{jets} #geq 6)&quot;</span><span class="p">,</span>          <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L346" class="blob-line-num js-line-number" data-line-number="346"></td>
        <td id="LC346" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L347" class="blob-line-num js-line-number" data-line-number="347"></td>
        <td id="LC347" class="blob-line-code js-file-line">    <span class="n">ZMass_Zexc0jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zexc0jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} = 0)&quot;</span><span class="p">,</span>             <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L348" class="blob-line-num js-line-number" data-line-number="348"></td>
        <td id="LC348" class="blob-line-code js-file-line">    <span class="n">ZMass_Zexc1jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zexc1jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} = 1)&quot;</span><span class="p">,</span>             <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L349" class="blob-line-num js-line-number" data-line-number="349"></td>
        <td id="LC349" class="blob-line-code js-file-line">    <span class="n">ZMass_Zexc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zexc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} = 2)&quot;</span><span class="p">,</span>             <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L350" class="blob-line-num js-line-number" data-line-number="350"></td>
        <td id="LC350" class="blob-line-code js-file-line">    <span class="n">ZMass_Zexc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zexc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} = 3)&quot;</span><span class="p">,</span>             <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L351" class="blob-line-num js-line-number" data-line-number="351"></td>
        <td id="LC351" class="blob-line-code js-file-line">    <span class="n">ZMass_Zexc4jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zexc4jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} = 4)&quot;</span><span class="p">,</span>             <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L352" class="blob-line-num js-line-number" data-line-number="352"></td>
        <td id="LC352" class="blob-line-code js-file-line">    <span class="n">ZMass_Zexc5jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zexc5jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} = 5)&quot;</span><span class="p">,</span>             <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L353" class="blob-line-num js-line-number" data-line-number="353"></td>
        <td id="LC353" class="blob-line-code js-file-line">    <span class="n">ZMass_Zexc6jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZMass_Zexc6jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;Z Invariant Mass (N_{jets} = 6)&quot;</span><span class="p">,</span>             <span class="n">Mll</span><span class="p">,</span>    <span class="mi">111</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">260</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L354" class="blob-line-num js-line-number" data-line-number="354"></td>
        <td id="LC354" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L355" class="blob-line-num js-line-number" data-line-number="355"></td>
        <td id="LC355" class="blob-line-code js-file-line">    <span class="n">ZPt_Zinc0jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zinc0jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} #geq 0)&quot;</span><span class="p">,</span>                   <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L356" class="blob-line-num js-line-number" data-line-number="356"></td>
        <td id="LC356" class="blob-line-code js-file-line">    <span class="n">ZPt_Zinc1jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zinc1jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>                   <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L357" class="blob-line-num js-line-number" data-line-number="357"></td>
        <td id="LC357" class="blob-line-code js-file-line">    <span class="n">ZPt_Zinc2jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zinc2jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                   <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L358" class="blob-line-num js-line-number" data-line-number="358"></td>
        <td id="LC358" class="blob-line-code js-file-line">    <span class="n">ZPt_Zinc3jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zinc3jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                   <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">300</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L359" class="blob-line-num js-line-number" data-line-number="359"></td>
        <td id="LC359" class="blob-line-code js-file-line">    <span class="n">ZPt_Zinc4jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zinc4jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>                   <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L360" class="blob-line-num js-line-number" data-line-number="360"></td>
        <td id="LC360" class="blob-line-code js-file-line">    <span class="n">ZPt_Zinc5jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zinc5jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>                   <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L361" class="blob-line-num js-line-number" data-line-number="361"></td>
        <td id="LC361" class="blob-line-code js-file-line">    <span class="n">ZPt_Zinc6jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zinc6jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>                   <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L362" class="blob-line-num js-line-number" data-line-number="362"></td>
        <td id="LC362" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L363" class="blob-line-num js-line-number" data-line-number="363"></td>
        <td id="LC363" class="blob-line-code js-file-line">    <span class="n">genZPt_Zinc0jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZPt_Zinc0jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;gen Z p_{T} (N_{jets} #geq 0)&quot;</span><span class="p">,</span>               <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L364" class="blob-line-num js-line-number" data-line-number="364"></td>
        <td id="LC364" class="blob-line-code js-file-line">    <span class="n">genZPt_Zinc1jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZPt_Zinc1jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;gen Z p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>               <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L365" class="blob-line-num js-line-number" data-line-number="365"></td>
        <td id="LC365" class="blob-line-code js-file-line">    <span class="n">genZPt_Zinc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZPt_Zinc2jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;gen Z p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>               <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L366" class="blob-line-num js-line-number" data-line-number="366"></td>
        <td id="LC366" class="blob-line-code js-file-line">    <span class="n">genZPt_Zinc3jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZPt_Zinc3jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;gen Z p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>               <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">300</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L367" class="blob-line-num js-line-number" data-line-number="367"></td>
        <td id="LC367" class="blob-line-code js-file-line">    <span class="n">genZPt_Zinc4jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZPt_Zinc4jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;gen Z p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>               <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L368" class="blob-line-num js-line-number" data-line-number="368"></td>
        <td id="LC368" class="blob-line-code js-file-line">    <span class="n">genZPt_Zinc5jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZPt_Zinc5jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;gen Z p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>               <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L369" class="blob-line-num js-line-number" data-line-number="369"></td>
        <td id="LC369" class="blob-line-code js-file-line">    <span class="n">genZPt_Zinc6jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZPt_Zinc6jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;gen Z p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>               <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L370" class="blob-line-num js-line-number" data-line-number="370"></td>
        <td id="LC370" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L371" class="blob-line-num js-line-number" data-line-number="371"></td>
        <td id="LC371" class="blob-line-code js-file-line">    <span class="n">ZPt_Zexc0jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zexc0jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} = 0)&quot;</span><span class="p">,</span>                      <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L372" class="blob-line-num js-line-number" data-line-number="372"></td>
        <td id="LC372" class="blob-line-code js-file-line">    <span class="n">ZPt_Zexc1jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zexc1jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} = 1)&quot;</span><span class="p">,</span>                      <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L373" class="blob-line-num js-line-number" data-line-number="373"></td>
        <td id="LC373" class="blob-line-code js-file-line">    <span class="n">ZPt_Zexc2jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zexc2jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} = 2)&quot;</span><span class="p">,</span>                      <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L374" class="blob-line-num js-line-number" data-line-number="374"></td>
        <td id="LC374" class="blob-line-code js-file-line">    <span class="n">ZPt_Zexc3jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zexc3jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} = 3)&quot;</span><span class="p">,</span>                      <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">300</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L375" class="blob-line-num js-line-number" data-line-number="375"></td>
        <td id="LC375" class="blob-line-code js-file-line">    <span class="n">ZPt_Zexc4jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zexc4jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} = 4)&quot;</span><span class="p">,</span>                      <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L376" class="blob-line-num js-line-number" data-line-number="376"></td>
        <td id="LC376" class="blob-line-code js-file-line">    <span class="n">ZPt_Zexc5jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zexc5jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} = 5)&quot;</span><span class="p">,</span>                      <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L377" class="blob-line-num js-line-number" data-line-number="377"></td>
        <td id="LC377" class="blob-line-code js-file-line">    <span class="n">ZPt_Zexc6jet</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZPt_Zexc6jet&quot;</span><span class="p">,</span>                        <span class="s">&quot;Z p_{T} (N_{jets} = 6)&quot;</span><span class="p">,</span>                      <span class="n">ZpT</span><span class="p">,</span>    <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L378" class="blob-line-num js-line-number" data-line-number="378"></td>
        <td id="LC378" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L379" class="blob-line-num js-line-number" data-line-number="379"></td>
        <td id="LC379" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L380" class="blob-line-num js-line-number" data-line-number="380"></td>
        <td id="LC380" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zinc0jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zinc0jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} #geq 0)&quot;</span><span class="p">,</span>                <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L381" class="blob-line-num js-line-number" data-line-number="381"></td>
        <td id="LC381" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zinc1jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zinc1jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} #geq 1)&quot;</span><span class="p">,</span>                <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L382" class="blob-line-num js-line-number" data-line-number="382"></td>
        <td id="LC382" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L383" class="blob-line-num js-line-number" data-line-number="383"></td>
        <td id="LC383" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zinc3jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zinc3jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L384" class="blob-line-num js-line-number" data-line-number="384"></td>
        <td id="LC384" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zinc4jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zinc4jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} #geq 4)&quot;</span><span class="p">,</span>                <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L385" class="blob-line-num js-line-number" data-line-number="385"></td>
        <td id="LC385" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zinc5jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zinc5jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} #geq 5)&quot;</span><span class="p">,</span>                <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L386" class="blob-line-num js-line-number" data-line-number="386"></td>
        <td id="LC386" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zinc6jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zinc6jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} #geq 6)&quot;</span><span class="p">,</span>                <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L387" class="blob-line-num js-line-number" data-line-number="387"></td>
        <td id="LC387" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L388" class="blob-line-num js-line-number" data-line-number="388"></td>
        <td id="LC388" class="blob-line-code js-file-line">    <span class="n">genZRapidity_Zinc0jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZRapidity_Zinc0jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen Z Rapidity (N_{jets} #geq 0)&quot;</span><span class="p">,</span>            <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L389" class="blob-line-num js-line-number" data-line-number="389"></td>
        <td id="LC389" class="blob-line-code js-file-line">    <span class="n">genZRapidity_Zinc1jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZRapidity_Zinc1jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen Z Rapidity (N_{jets} #geq 1)&quot;</span><span class="p">,</span>            <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L390" class="blob-line-num js-line-number" data-line-number="390"></td>
        <td id="LC390" class="blob-line-code js-file-line">    <span class="n">genZRapidity_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZRapidity_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen Z Rapidity (N_{jets} #geq 2)&quot;</span><span class="p">,</span>            <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L391" class="blob-line-num js-line-number" data-line-number="391"></td>
        <td id="LC391" class="blob-line-code js-file-line">    <span class="n">genZRapidity_Zinc3jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZRapidity_Zinc3jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen Z Rapidity (N_{jets} #geq 3)&quot;</span><span class="p">,</span>            <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L392" class="blob-line-num js-line-number" data-line-number="392"></td>
        <td id="LC392" class="blob-line-code js-file-line">    <span class="n">genZRapidity_Zinc4jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZRapidity_Zinc4jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen Z Rapidity (N_{jets} #geq 4)&quot;</span><span class="p">,</span>            <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L393" class="blob-line-num js-line-number" data-line-number="393"></td>
        <td id="LC393" class="blob-line-code js-file-line">    <span class="n">genZRapidity_Zinc5jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZRapidity_Zinc5jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen Z Rapidity (N_{jets} #geq 5)&quot;</span><span class="p">,</span>            <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L394" class="blob-line-num js-line-number" data-line-number="394"></td>
        <td id="LC394" class="blob-line-code js-file-line">    <span class="n">genZRapidity_Zinc6jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZRapidity_Zinc6jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen Z Rapidity (N_{jets} #geq 6)&quot;</span><span class="p">,</span>            <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L395" class="blob-line-num js-line-number" data-line-number="395"></td>
        <td id="LC395" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L396" class="blob-line-num js-line-number" data-line-number="396"></td>
        <td id="LC396" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zexc0jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zexc0jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} = 0)&quot;</span><span class="p">,</span>                   <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L397" class="blob-line-num js-line-number" data-line-number="397"></td>
        <td id="LC397" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zexc1jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zexc1jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} = 1)&quot;</span><span class="p">,</span>                   <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L398" class="blob-line-num js-line-number" data-line-number="398"></td>
        <td id="LC398" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zexc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zexc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} = 2)&quot;</span><span class="p">,</span>                   <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L399" class="blob-line-num js-line-number" data-line-number="399"></td>
        <td id="LC399" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zexc3jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zexc3jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} = 3)&quot;</span><span class="p">,</span>                   <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L400" class="blob-line-num js-line-number" data-line-number="400"></td>
        <td id="LC400" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zexc4jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zexc4jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} = 4)&quot;</span><span class="p">,</span>                   <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L401" class="blob-line-num js-line-number" data-line-number="401"></td>
        <td id="LC401" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zexc5jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zexc5jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} = 5)&quot;</span><span class="p">,</span>                   <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L402" class="blob-line-num js-line-number" data-line-number="402"></td>
        <td id="LC402" class="blob-line-code js-file-line">    <span class="n">ZRapidity_Zexc6jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZRapidity_Zexc6jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Z Rapidity (N_{jets} = 6)&quot;</span><span class="p">,</span>                   <span class="n">Zrap</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L403" class="blob-line-num js-line-number" data-line-number="403"></td>
        <td id="LC403" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L404" class="blob-line-num js-line-number" data-line-number="404"></td>
        <td id="LC404" class="blob-line-code js-file-line">    <span class="n">ZEta_Zinc0jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zinc0jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} #geq 0)&quot;</span><span class="p">,</span>                    <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L405" class="blob-line-num js-line-number" data-line-number="405"></td>
        <td id="LC405" class="blob-line-code js-file-line">    <span class="n">ZEta_Zinc1jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zinc1jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>                    <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L406" class="blob-line-num js-line-number" data-line-number="406"></td>
        <td id="LC406" class="blob-line-code js-file-line">    <span class="n">ZEta_Zinc2jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zinc2jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                    <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L407" class="blob-line-num js-line-number" data-line-number="407"></td>
        <td id="LC407" class="blob-line-code js-file-line">    <span class="n">ZEta_Zinc3jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zinc3jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                    <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L408" class="blob-line-num js-line-number" data-line-number="408"></td>
        <td id="LC408" class="blob-line-code js-file-line">    <span class="n">ZEta_Zinc4jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zinc4jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>                    <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L409" class="blob-line-num js-line-number" data-line-number="409"></td>
        <td id="LC409" class="blob-line-code js-file-line">    <span class="n">ZEta_Zinc5jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zinc5jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} #geq 5)&quot;</span><span class="p">,</span>                    <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L410" class="blob-line-num js-line-number" data-line-number="410"></td>
        <td id="LC410" class="blob-line-code js-file-line">    <span class="n">ZEta_Zinc6jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zinc6jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} #geq 6)&quot;</span><span class="p">,</span>                    <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L411" class="blob-line-num js-line-number" data-line-number="411"></td>
        <td id="LC411" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L412" class="blob-line-num js-line-number" data-line-number="412"></td>
        <td id="LC412" class="blob-line-code js-file-line">    <span class="n">genZEta_Zinc0jet</span>                    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZEta_Zinc0jet&quot;</span><span class="p">,</span>                    <span class="s">&quot;gen Z #eta (N_{jets} #geq 0)&quot;</span><span class="p">,</span>                <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L413" class="blob-line-num js-line-number" data-line-number="413"></td>
        <td id="LC413" class="blob-line-code js-file-line">    <span class="n">genZEta_Zinc1jet</span>                    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZEta_Zinc1jet&quot;</span><span class="p">,</span>                    <span class="s">&quot;gen Z #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>                <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L414" class="blob-line-num js-line-number" data-line-number="414"></td>
        <td id="LC414" class="blob-line-code js-file-line">    <span class="n">genZEta_Zinc2jet</span>                    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZEta_Zinc2jet&quot;</span><span class="p">,</span>                    <span class="s">&quot;gen Z #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L415" class="blob-line-num js-line-number" data-line-number="415"></td>
        <td id="LC415" class="blob-line-code js-file-line">    <span class="n">genZEta_Zinc3jet</span>                    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZEta_Zinc3jet&quot;</span><span class="p">,</span>                    <span class="s">&quot;gen Z #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L416" class="blob-line-num js-line-number" data-line-number="416"></td>
        <td id="LC416" class="blob-line-code js-file-line">    <span class="n">genZEta_Zinc4jet</span>                    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZEta_Zinc4jet&quot;</span><span class="p">,</span>                    <span class="s">&quot;gen Z #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>                <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L417" class="blob-line-num js-line-number" data-line-number="417"></td>
        <td id="LC417" class="blob-line-code js-file-line">    <span class="n">genZEta_Zinc5jet</span>                    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZEta_Zinc5jet&quot;</span><span class="p">,</span>                    <span class="s">&quot;gen Z #eta (N_{jets} #geq 5)&quot;</span><span class="p">,</span>                <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L418" class="blob-line-num js-line-number" data-line-number="418"></td>
        <td id="LC418" class="blob-line-code js-file-line">    <span class="n">genZEta_Zinc6jet</span>                    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZEta_Zinc6jet&quot;</span><span class="p">,</span>                    <span class="s">&quot;gen Z #eta (N_{jets} #geq 6)&quot;</span><span class="p">,</span>                <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L419" class="blob-line-num js-line-number" data-line-number="419"></td>
        <td id="LC419" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L420" class="blob-line-num js-line-number" data-line-number="420"></td>
        <td id="LC420" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L421" class="blob-line-num js-line-number" data-line-number="421"></td>
        <td id="LC421" class="blob-line-code js-file-line">    <span class="n">ZEta_Zexc0jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zexc0jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} = 0)&quot;</span><span class="p">,</span>                       <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L422" class="blob-line-num js-line-number" data-line-number="422"></td>
        <td id="LC422" class="blob-line-code js-file-line">    <span class="n">ZEta_Zexc1jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zexc1jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} = 1)&quot;</span><span class="p">,</span>                       <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L423" class="blob-line-num js-line-number" data-line-number="423"></td>
        <td id="LC423" class="blob-line-code js-file-line">    <span class="n">ZEta_Zexc2jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zexc2jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} = 2)&quot;</span><span class="p">,</span>                       <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L424" class="blob-line-num js-line-number" data-line-number="424"></td>
        <td id="LC424" class="blob-line-code js-file-line">    <span class="n">ZEta_Zexc3jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zexc3jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} = 3)&quot;</span><span class="p">,</span>                       <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L425" class="blob-line-num js-line-number" data-line-number="425"></td>
        <td id="LC425" class="blob-line-code js-file-line">    <span class="n">ZEta_Zexc4jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zexc4jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} = 4)&quot;</span><span class="p">,</span>                       <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L426" class="blob-line-num js-line-number" data-line-number="426"></td>
        <td id="LC426" class="blob-line-code js-file-line">    <span class="n">ZEta_Zexc5jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zexc5jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} = 5)&quot;</span><span class="p">,</span>                       <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L427" class="blob-line-num js-line-number" data-line-number="427"></td>
        <td id="LC427" class="blob-line-code js-file-line">    <span class="n">ZEta_Zexc6jet</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZEta_Zexc6jet&quot;</span><span class="p">,</span>                       <span class="s">&quot;Z #eta (N_{jets} = 6)&quot;</span><span class="p">,</span>                       <span class="n">Zeta</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="mi">3</span><span class="p">,</span> <span class="mi">3</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L428" class="blob-line-num js-line-number" data-line-number="428"></td>
        <td id="LC428" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L429" class="blob-line-num js-line-number" data-line-number="429"></td>
        <td id="LC429" class="blob-line-code js-file-line">    <span class="n">lepEta_Zinc0jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zinc0jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 0)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L430" class="blob-line-num js-line-number" data-line-number="430"></td>
        <td id="LC430" class="blob-line-code js-file-line">    <span class="n">lepEta_Zinc1jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zinc1jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L431" class="blob-line-num js-line-number" data-line-number="431"></td>
        <td id="LC431" class="blob-line-code js-file-line">    <span class="n">lepEta_Zinc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zinc2jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L432" class="blob-line-num js-line-number" data-line-number="432"></td>
        <td id="LC432" class="blob-line-code js-file-line">    <span class="n">lepEta_Zinc3jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zinc3jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L433" class="blob-line-num js-line-number" data-line-number="433"></td>
        <td id="LC433" class="blob-line-code js-file-line">    <span class="n">lepEta_Zinc4jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zinc4jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L434" class="blob-line-num js-line-number" data-line-number="434"></td>
        <td id="LC434" class="blob-line-code js-file-line">    <span class="n">lepEta_Zinc5jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zinc5jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 5)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L435" class="blob-line-num js-line-number" data-line-number="435"></td>
        <td id="LC435" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L436" class="blob-line-num js-line-number" data-line-number="436"></td>
        <td id="LC436" class="blob-line-code js-file-line">    <span class="n">lepPhi_Zinc0jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPhi_Zinc0jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #phi (N_{jets} #geq 0)&quot;</span><span class="p">,</span>           <span class="n">lphi</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L437" class="blob-line-num js-line-number" data-line-number="437"></td>
        <td id="LC437" class="blob-line-code js-file-line">    <span class="n">lepPhi_Zinc1jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPhi_Zinc1jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #phi (N_{jets} #geq 1)&quot;</span><span class="p">,</span>           <span class="n">lphi</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L438" class="blob-line-num js-line-number" data-line-number="438"></td>
        <td id="LC438" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L439" class="blob-line-num js-line-number" data-line-number="439"></td>
        <td id="LC439" class="blob-line-code js-file-line">    <span class="n">genlepEta_Zinc0jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genlepEta_Zinc0jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 0)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L440" class="blob-line-num js-line-number" data-line-number="440"></td>
        <td id="LC440" class="blob-line-code js-file-line">    <span class="n">genlepEta_Zinc1jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genlepEta_Zinc1jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L441" class="blob-line-num js-line-number" data-line-number="441"></td>
        <td id="LC441" class="blob-line-code js-file-line">    <span class="n">genlepEta_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genlepEta_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>        <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L442" class="blob-line-num js-line-number" data-line-number="442"></td>
        <td id="LC442" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L443" class="blob-line-num js-line-number" data-line-number="443"></td>
        <td id="LC443" class="blob-line-code js-file-line">    <span class="n">lepEta_Zexc0jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zexc0jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} = 0)&quot;</span><span class="p">,</span>           <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L444" class="blob-line-num js-line-number" data-line-number="444"></td>
        <td id="LC444" class="blob-line-code js-file-line">    <span class="n">lepEta_Zexc1jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zexc1jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} = 1)&quot;</span><span class="p">,</span>           <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L445" class="blob-line-num js-line-number" data-line-number="445"></td>
        <td id="LC445" class="blob-line-code js-file-line">    <span class="n">lepEta_Zexc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zexc2jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} = 2)&quot;</span><span class="p">,</span>           <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L446" class="blob-line-num js-line-number" data-line-number="446"></td>
        <td id="LC446" class="blob-line-code js-file-line">    <span class="n">lepEta_Zexc3jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zexc3jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} = 3)&quot;</span><span class="p">,</span>           <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L447" class="blob-line-num js-line-number" data-line-number="447"></td>
        <td id="LC447" class="blob-line-code js-file-line">    <span class="n">lepEta_Zexc4jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zexc4jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} = 4)&quot;</span><span class="p">,</span>           <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L448" class="blob-line-num js-line-number" data-line-number="448"></td>
        <td id="LC448" class="blob-line-code js-file-line">    <span class="n">lepEta_Zexc5jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepEta_Zexc5jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #eta (N_{jets} = 5)&quot;</span><span class="p">,</span>           <span class="n">leta</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L449" class="blob-line-num js-line-number" data-line-number="449"></td>
        <td id="LC449" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L450" class="blob-line-num js-line-number" data-line-number="450"></td>
        <td id="LC450" class="blob-line-code js-file-line">    <span class="n">lepPhi_Zexc0jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPhi_Zexc0jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #phi (N_{jets} = 0)&quot;</span><span class="p">,</span>           <span class="n">lphi</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L451" class="blob-line-num js-line-number" data-line-number="451"></td>
        <td id="LC451" class="blob-line-code js-file-line">    <span class="n">lepPhi_Zexc1jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPhi_Zexc1jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #phi (N_{jets} = 1)&quot;</span><span class="p">,</span>           <span class="n">lphi</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L452" class="blob-line-num js-line-number" data-line-number="452"></td>
        <td id="LC452" class="blob-line-code js-file-line">    <span class="n">lepPhi_Zexc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPhi_Zexc2jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #phi (N_{jets} = 2)&quot;</span><span class="p">,</span>           <span class="n">lphi</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L453" class="blob-line-num js-line-number" data-line-number="453"></td>
        <td id="LC453" class="blob-line-code js-file-line">    <span class="n">lepPhi_Zexc3jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPhi_Zexc3jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #phi (N_{jets} = 3)&quot;</span><span class="p">,</span>           <span class="n">lphi</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L454" class="blob-line-num js-line-number" data-line-number="454"></td>
        <td id="LC454" class="blob-line-code js-file-line">    <span class="n">lepPhi_Zexc4jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPhi_Zexc4jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #phi (N_{jets} = 4)&quot;</span><span class="p">,</span>           <span class="n">lphi</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L455" class="blob-line-num js-line-number" data-line-number="455"></td>
        <td id="LC455" class="blob-line-code js-file-line">    <span class="n">lepPhi_Zexc5jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPhi_Zexc5jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;1st &amp; 2nd lep #phi (N_{jets} = 5)&quot;</span><span class="p">,</span>           <span class="n">lphi</span><span class="p">,</span>   <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L456" class="blob-line-num js-line-number" data-line-number="456"></td>
        <td id="LC456" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L457" class="blob-line-num js-line-number" data-line-number="457"></td>
        <td id="LC457" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L458" class="blob-line-num js-line-number" data-line-number="458"></td>
        <td id="LC458" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L459" class="blob-line-num js-line-number" data-line-number="459"></td>
        <td id="LC459" class="blob-line-code js-file-line">    <span class="n">lepEtaEta_Zinc0jet</span>                  <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;lepEtaEta_Zinc0jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#eta #eta (N_{jets} #geq 0)&quot;</span><span class="p">,</span>                  <span class="mi">12</span><span class="p">,</span> <span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">,</span> <span class="mi">12</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L460" class="blob-line-num js-line-number" data-line-number="460"></td>
        <td id="LC460" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L461" class="blob-line-num js-line-number" data-line-number="461"></td>
        <td id="LC461" class="blob-line-code js-file-line">    <span class="n">FirstJetEtaFull_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetEtaFull_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;1st jet #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">48</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L462" class="blob-line-num js-line-number" data-line-number="462"></td>
        <td id="LC462" class="blob-line-code js-file-line">    <span class="n">SecondJetEtaFull_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetEtaFull_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;2nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">48</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L463" class="blob-line-num js-line-number" data-line-number="463"></td>
        <td id="LC463" class="blob-line-code js-file-line">    <span class="n">ThirdJetEtaFull_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetEtaFull_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;3rd jet #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">16</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L464" class="blob-line-num js-line-number" data-line-number="464"></td>
        <td id="LC464" class="blob-line-code js-file-line">    <span class="n">FourthJetEtaFull_Zinc4jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FourthJetEtaFull_Zinc4jet&quot;</span><span class="p">,</span>               <span class="s">&quot;4th jet #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{4})&quot;</span><span class="p">,</span>   <span class="mi">8</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L465" class="blob-line-num js-line-number" data-line-number="465"></td>
        <td id="LC465" class="blob-line-code js-file-line">    <span class="n">FifthJetEtaFull_Zinc5jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FifthJetEtaFull_Zinc5jet&quot;</span><span class="p">,</span>                <span class="s">&quot;5th jet #eta (N_{jets} #geq 5)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{5})&quot;</span><span class="p">,</span>   <span class="mi">4</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L466" class="blob-line-num js-line-number" data-line-number="466"></td>
        <td id="LC466" class="blob-line-code js-file-line">    <span class="n">SixthJetEtaFull_Zinc6jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SixthJetEtaFull_Zinc6jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#geq 6th jets #eta (N_{jets} #geq 6)&quot;</span><span class="p">,</span>        <span class="s">&quot;#eta(j_{6})&quot;</span><span class="p">,</span>   <span class="mi">4</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L467" class="blob-line-num js-line-number" data-line-number="467"></td>
        <td id="LC467" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L468" class="blob-line-num js-line-number" data-line-number="468"></td>
        <td id="LC468" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L469" class="blob-line-num js-line-number" data-line-number="469"></td>
        <td id="LC469" class="blob-line-code js-file-line">    <span class="n">FirstJetEta_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetEta_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;1st jet #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">32</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L470" class="blob-line-num js-line-number" data-line-number="470"></td>
        <td id="LC470" class="blob-line-code js-file-line">    <span class="n">SecondJetEta_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetEta_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;2nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">32</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L471" class="blob-line-num js-line-number" data-line-number="471"></td>
        <td id="LC471" class="blob-line-code js-file-line">    <span class="n">ThirdJetEta_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetEta_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;3rd jet #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L472" class="blob-line-num js-line-number" data-line-number="472"></td>
        <td id="LC472" class="blob-line-code js-file-line">    <span class="n">FourthJetEta_Zinc4jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FourthJetEta_Zinc4jet&quot;</span><span class="p">,</span>               <span class="s">&quot;4th jet #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{4})&quot;</span><span class="p">,</span>  <span class="mi">12</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L473" class="blob-line-num js-line-number" data-line-number="473"></td>
        <td id="LC473" class="blob-line-code js-file-line">    <span class="n">FifthJetEta_Zinc5jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FifthJetEta_Zinc5jet&quot;</span><span class="p">,</span>                <span class="s">&quot;5th jet #eta (N_{jets} #geq 5)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{5})&quot;</span><span class="p">,</span>   <span class="mi">6</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L474" class="blob-line-num js-line-number" data-line-number="474"></td>
        <td id="LC474" class="blob-line-code js-file-line">    <span class="n">SixthJetEta_Zinc6jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SixthJetEta_Zinc6jet&quot;</span><span class="p">,</span>                <span class="s">&quot;6th jet #eta (N_{jets} #geq 6)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{6})&quot;</span><span class="p">,</span>   <span class="mi">6</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L475" class="blob-line-num js-line-number" data-line-number="475"></td>
        <td id="LC475" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L476" class="blob-line-num js-line-number" data-line-number="476"></td>
        <td id="LC476" class="blob-line-code js-file-line">    <span class="n">genFirstJetEta_Zinc1jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetEta_Zinc1jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen 1st jet #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>          <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">32</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L477" class="blob-line-num js-line-number" data-line-number="477"></td>
        <td id="LC477" class="blob-line-code js-file-line">    <span class="n">genSecondJetEta_Zinc2jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetEta_Zinc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 2nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>          <span class="s">&quot;#eta(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">32</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L478" class="blob-line-num js-line-number" data-line-number="478"></td>
        <td id="LC478" class="blob-line-code js-file-line">    <span class="n">genThirdJetEta_Zinc3jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetEta_Zinc3jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen 3rd jet #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>          <span class="s">&quot;#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L479" class="blob-line-num js-line-number" data-line-number="479"></td>
        <td id="LC479" class="blob-line-code js-file-line">    <span class="n">genFourthJetEta_Zinc4jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFourthJetEta_Zinc4jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 4th jet #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>          <span class="s">&quot;#eta(j_{4})&quot;</span><span class="p">,</span>  <span class="mi">12</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L480" class="blob-line-num js-line-number" data-line-number="480"></td>
        <td id="LC480" class="blob-line-code js-file-line">    <span class="n">genFifthJetEta_Zinc5jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFifthJetEta_Zinc5jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen 5th jet #eta (N_{jets} #geq 5)&quot;</span><span class="p">,</span>          <span class="s">&quot;#eta(j_{5})&quot;</span><span class="p">,</span>   <span class="mi">6</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L481" class="blob-line-num js-line-number" data-line-number="481"></td>
        <td id="LC481" class="blob-line-code js-file-line">    <span class="n">genSixthJetEta_Zinc6jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSixthJetEta_Zinc6jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen 6th jet #eta (N_{jets} #geq 6)&quot;</span><span class="p">,</span>          <span class="s">&quot;#eta(j_{6})&quot;</span><span class="p">,</span>   <span class="mi">6</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L482" class="blob-line-num js-line-number" data-line-number="482"></td>
        <td id="LC482" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L483" class="blob-line-num js-line-number" data-line-number="483"></td>
        <td id="LC483" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L484" class="blob-line-num js-line-number" data-line-number="484"></td>
        <td id="LC484" class="blob-line-code js-file-line">    <span class="n">FirstJetEta_Zexc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetEta_Zexc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;1st jet #eta (N_{jets} = 1)&quot;</span><span class="p">,</span>                 <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">47</span><span class="p">,</span><span class="o">-</span><span class="mf">4.7</span><span class="p">,</span> <span class="mf">4.7</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L485" class="blob-line-num js-line-number" data-line-number="485"></td>
        <td id="LC485" class="blob-line-code js-file-line">    <span class="n">SecondJetEta_Zexc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetEta_Zexc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;2nd jet #eta (N_{jets} = 2)&quot;</span><span class="p">,</span>                 <span class="s">&quot;#eta(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">47</span><span class="p">,</span><span class="o">-</span><span class="mf">4.7</span><span class="p">,</span> <span class="mf">4.7</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L486" class="blob-line-num js-line-number" data-line-number="486"></td>
        <td id="LC486" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L487" class="blob-line-num js-line-number" data-line-number="487"></td>
        <td id="LC487" class="blob-line-code js-file-line">    <span class="n">AllJetEta_Zinc1jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetEta_Zinc1jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;All jets #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>             <span class="s">&quot;#eta(jets)&quot;</span><span class="p">,</span>   <span class="mi">47</span><span class="p">,</span><span class="o">-</span><span class="mf">4.7</span><span class="p">,</span> <span class="mf">4.7</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L488" class="blob-line-num js-line-number" data-line-number="488"></td>
        <td id="LC488" class="blob-line-code js-file-line">    <span class="n">AllJetEta_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetEta_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;All jets #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;#eta(jets)&quot;</span><span class="p">,</span>   <span class="mi">47</span><span class="p">,</span><span class="o">-</span><span class="mf">4.7</span><span class="p">,</span> <span class="mf">4.7</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L489" class="blob-line-num js-line-number" data-line-number="489"></td>
        <td id="LC489" class="blob-line-code js-file-line">    <span class="n">AllJetEta_Zinc3jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetEta_Zinc3jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;All jets #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>             <span class="s">&quot;#eta(jets)&quot;</span><span class="p">,</span>   <span class="mi">47</span><span class="p">,</span><span class="o">-</span><span class="mf">4.7</span><span class="p">,</span> <span class="mf">4.7</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L490" class="blob-line-num js-line-number" data-line-number="490"></td>
        <td id="LC490" class="blob-line-code js-file-line">    <span class="n">AllJetEta_Zinc4jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetEta_Zinc4jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;All jets #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>             <span class="s">&quot;#eta(jets)&quot;</span><span class="p">,</span>   <span class="mi">47</span><span class="p">,</span><span class="o">-</span><span class="mf">4.7</span><span class="p">,</span> <span class="mf">4.7</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L491" class="blob-line-num js-line-number" data-line-number="491"></td>
        <td id="LC491" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L492" class="blob-line-num js-line-number" data-line-number="492"></td>
        <td id="LC492" class="blob-line-code js-file-line">    <span class="n">FirstJetPhi_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPhi_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;1st jet #phi (N_{jets} #geq 1)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L493" class="blob-line-num js-line-number" data-line-number="493"></td>
        <td id="LC493" class="blob-line-code js-file-line">    <span class="n">SecondJetPhi_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPhi_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;2nd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L494" class="blob-line-num js-line-number" data-line-number="494"></td>
        <td id="LC494" class="blob-line-code js-file-line">    <span class="n">ThirdJetPhi_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPhi_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;3rd jet #phi (N_{jets} #geq 3)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L495" class="blob-line-num js-line-number" data-line-number="495"></td>
        <td id="LC495" class="blob-line-code js-file-line">    <span class="n">FourthJetPhi_Zinc4jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FourthJetPhi_Zinc4jet&quot;</span><span class="p">,</span>               <span class="s">&quot;4th jet #phi (N_{jets} #geq 4)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{4})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L496" class="blob-line-num js-line-number" data-line-number="496"></td>
        <td id="LC496" class="blob-line-code js-file-line">    <span class="n">FifthJetPhi_Zinc5jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FifthJetPhi_Zinc5jet&quot;</span><span class="p">,</span>                <span class="s">&quot;5th jet #phi (N_{jets} #geq 5)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{5})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L497" class="blob-line-num js-line-number" data-line-number="497"></td>
        <td id="LC497" class="blob-line-code js-file-line">    <span class="n">SixthJetPhi_Zinc6jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SixthJetPhi_Zinc6jet&quot;</span><span class="p">,</span>                <span class="s">&quot;6th jet #phi (N_{jets} #geq 6)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{6})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L498" class="blob-line-num js-line-number" data-line-number="498"></td>
        <td id="LC498" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L499" class="blob-line-num js-line-number" data-line-number="499"></td>
        <td id="LC499" class="blob-line-code js-file-line">    <span class="n">FirstJetPhi_Zexc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPhi_Zexc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;1st jet #phi (N_{jets} = 1)&quot;</span><span class="p">,</span>                 <span class="s">&quot;#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L500" class="blob-line-num js-line-number" data-line-number="500"></td>
        <td id="LC500" class="blob-line-code js-file-line">    <span class="n">SecondJetPhi_Zexc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPhi_Zexc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;2nd jet #phi (N_{jets} = 2)&quot;</span><span class="p">,</span>                 <span class="s">&quot;#phi(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L501" class="blob-line-num js-line-number" data-line-number="501"></td>
        <td id="LC501" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L502" class="blob-line-num js-line-number" data-line-number="502"></td>
        <td id="LC502" class="blob-line-code js-file-line">    <span class="n">AllJetPhi_Zinc1jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPhi_Zinc1jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;All jets #phi (N_{jets} #geq 1)&quot;</span><span class="p">,</span>             <span class="s">&quot;#phi(jets)&quot;</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L503" class="blob-line-num js-line-number" data-line-number="503"></td>
        <td id="LC503" class="blob-line-code js-file-line">    <span class="n">AllJetPhi_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPhi_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;All jets #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;#phi(jets)&quot;</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L504" class="blob-line-num js-line-number" data-line-number="504"></td>
        <td id="LC504" class="blob-line-code js-file-line">    <span class="n">AllJetPhi_Zinc3jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPhi_Zinc3jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;All jets #phi (N_{jets} #geq 3)&quot;</span><span class="p">,</span>             <span class="s">&quot;#phi(jets)&quot;</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L505" class="blob-line-num js-line-number" data-line-number="505"></td>
        <td id="LC505" class="blob-line-code js-file-line">    <span class="n">AllJetPhi_Zinc4jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPhi_Zinc4jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;All jets #phi (N_{jets} #geq 4)&quot;</span><span class="p">,</span>             <span class="s">&quot;#phi(jets)&quot;</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L506" class="blob-line-num js-line-number" data-line-number="506"></td>
        <td id="LC506" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L507" class="blob-line-num js-line-number" data-line-number="507"></td>
        <td id="LC507" class="blob-line-code js-file-line">    <span class="n">lepPt_Zinc0jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zinc0jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} #geq 0)&quot;</span><span class="p">,</span>       <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L508" class="blob-line-num js-line-number" data-line-number="508"></td>
        <td id="LC508" class="blob-line-code js-file-line">    <span class="n">lepPt_Zinc1jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zinc1jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>       <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L509" class="blob-line-num js-line-number" data-line-number="509"></td>
        <td id="LC509" class="blob-line-code js-file-line">    <span class="n">lepPt_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zinc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>       <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L510" class="blob-line-num js-line-number" data-line-number="510"></td>
        <td id="LC510" class="blob-line-code js-file-line">    <span class="n">lepPt_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zinc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>       <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L511" class="blob-line-num js-line-number" data-line-number="511"></td>
        <td id="LC511" class="blob-line-code js-file-line">    <span class="n">lepPt_Zinc4jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zinc4jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>       <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L512" class="blob-line-num js-line-number" data-line-number="512"></td>
        <td id="LC512" class="blob-line-code js-file-line">    <span class="n">lepPt_Zinc5jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zinc5jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>       <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L513" class="blob-line-num js-line-number" data-line-number="513"></td>
        <td id="LC513" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L514" class="blob-line-num js-line-number" data-line-number="514"></td>
        <td id="LC514" class="blob-line-code js-file-line">    <span class="n">genlepPt_Zinc0jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genlepPt_Zinc0jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;gen 1st &amp; 2nd lep p_{T} (N_{jets} #geq 0)&quot;</span><span class="p">,</span>   <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L515" class="blob-line-num js-line-number" data-line-number="515"></td>
        <td id="LC515" class="blob-line-code js-file-line">    <span class="n">genlepPt_Zinc1jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genlepPt_Zinc1jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;gen 1st &amp; 2nd lep p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>   <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L516" class="blob-line-num js-line-number" data-line-number="516"></td>
        <td id="LC516" class="blob-line-code js-file-line">    <span class="n">genlepPt_Zinc2jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genlepPt_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;gen 1st &amp; 2nd lep p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>   <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L517" class="blob-line-num js-line-number" data-line-number="517"></td>
        <td id="LC517" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L518" class="blob-line-num js-line-number" data-line-number="518"></td>
        <td id="LC518" class="blob-line-code js-file-line">    <span class="n">lepPt_Zexc0jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zexc0jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} = 0)&quot;</span><span class="p">,</span>          <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L519" class="blob-line-num js-line-number" data-line-number="519"></td>
        <td id="LC519" class="blob-line-code js-file-line">    <span class="n">lepPt_Zexc1jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zexc1jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} = 1)&quot;</span><span class="p">,</span>          <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L520" class="blob-line-num js-line-number" data-line-number="520"></td>
        <td id="LC520" class="blob-line-code js-file-line">    <span class="n">lepPt_Zexc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zexc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} = 2)&quot;</span><span class="p">,</span>          <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L521" class="blob-line-num js-line-number" data-line-number="521"></td>
        <td id="LC521" class="blob-line-code js-file-line">    <span class="n">lepPt_Zexc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zexc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} = 3)&quot;</span><span class="p">,</span>          <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L522" class="blob-line-num js-line-number" data-line-number="522"></td>
        <td id="LC522" class="blob-line-code js-file-line">    <span class="n">lepPt_Zexc4jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zexc4jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} = 4)&quot;</span><span class="p">,</span>          <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L523" class="blob-line-num js-line-number" data-line-number="523"></td>
        <td id="LC523" class="blob-line-code js-file-line">    <span class="n">lepPt_Zexc5jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;lepPt_Zexc5jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;1st &amp; 2nd lep p_{T} (N_{jets} = 5)&quot;</span><span class="p">,</span>          <span class="n">lpT</span><span class="p">,</span>     <span class="mi">40</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">200</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L524" class="blob-line-num js-line-number" data-line-number="524"></td>
        <td id="LC524" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L525" class="blob-line-num js-line-number" data-line-number="525"></td>
        <td id="LC525" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L526" class="blob-line-num js-line-number" data-line-number="526"></td>
        <td id="LC526" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zexc0jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zexc0jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} = 0)&quot;</span><span class="p">,</span>          <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L527" class="blob-line-num js-line-number" data-line-number="527"></td>
        <td id="LC527" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zexc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zexc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} = 1)&quot;</span><span class="p">,</span>          <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L528" class="blob-line-num js-line-number" data-line-number="528"></td>
        <td id="LC528" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zexc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zexc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} = 2)&quot;</span><span class="p">,</span>          <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L529" class="blob-line-num js-line-number" data-line-number="529"></td>
        <td id="LC529" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zexc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zexc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} = 3)&quot;</span><span class="p">,</span>          <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L530" class="blob-line-num js-line-number" data-line-number="530"></td>
        <td id="LC530" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zexc4jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zexc4jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} = 4)&quot;</span><span class="p">,</span>          <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L531" class="blob-line-num js-line-number" data-line-number="531"></td>
        <td id="LC531" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zexc5jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zexc5jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} = 5)&quot;</span><span class="p">,</span>          <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L532" class="blob-line-num js-line-number" data-line-number="532"></td>
        <td id="LC532" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L533" class="blob-line-num js-line-number" data-line-number="533"></td>
        <td id="LC533" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zinc0jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zinc0jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} #geq 0)&quot;</span><span class="p">,</span>       <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L534" class="blob-line-num js-line-number" data-line-number="534"></td>
        <td id="LC534" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} #geq 1)&quot;</span><span class="p">,</span>       <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L535" class="blob-line-num js-line-number" data-line-number="535"></td>
        <td id="LC535" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} #geq 2)&quot;</span><span class="p">,</span>       <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L536" class="blob-line-num js-line-number" data-line-number="536"></td>
        <td id="LC536" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} #geq 3)&quot;</span><span class="p">,</span>       <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L537" class="blob-line-num js-line-number" data-line-number="537"></td>
        <td id="LC537" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zinc4jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zinc4jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} #geq 4)&quot;</span><span class="p">,</span>       <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L538" class="blob-line-num js-line-number" data-line-number="538"></td>
        <td id="LC538" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_Zinc5jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_Zinc5jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #phi btw lep (N_{jets} #geq 5)&quot;</span><span class="p">,</span>       <span class="n">ldPhi</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L539" class="blob-line-num js-line-number" data-line-number="539"></td>
        <td id="LC539" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L540" class="blob-line-num js-line-number" data-line-number="540"></td>
        <td id="LC540" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zexc0jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zexc0jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} = 0)&quot;</span><span class="p">,</span>          <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L541" class="blob-line-num js-line-number" data-line-number="541"></td>
        <td id="LC541" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zexc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zexc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} = 1)&quot;</span><span class="p">,</span>          <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L542" class="blob-line-num js-line-number" data-line-number="542"></td>
        <td id="LC542" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zexc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zexc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} = 2)&quot;</span><span class="p">,</span>          <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L543" class="blob-line-num js-line-number" data-line-number="543"></td>
        <td id="LC543" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zexc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zexc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} = 3)&quot;</span><span class="p">,</span>          <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L544" class="blob-line-num js-line-number" data-line-number="544"></td>
        <td id="LC544" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zexc4jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zexc4jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} = 4)&quot;</span><span class="p">,</span>          <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L545" class="blob-line-num js-line-number" data-line-number="545"></td>
        <td id="LC545" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zexc5jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zexc5jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} = 5)&quot;</span><span class="p">,</span>          <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L546" class="blob-line-num js-line-number" data-line-number="546"></td>
        <td id="LC546" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L547" class="blob-line-num js-line-number" data-line-number="547"></td>
        <td id="LC547" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zinc0jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zinc0jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} #geq 0)&quot;</span><span class="p">,</span>       <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L548" class="blob-line-num js-line-number" data-line-number="548"></td>
        <td id="LC548" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} #geq 1)&quot;</span><span class="p">,</span>       <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L549" class="blob-line-num js-line-number" data-line-number="549"></td>
        <td id="LC549" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} #geq 2)&quot;</span><span class="p">,</span>       <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L550" class="blob-line-num js-line-number" data-line-number="550"></td>
        <td id="LC550" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} #geq 3)&quot;</span><span class="p">,</span>       <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L551" class="blob-line-num js-line-number" data-line-number="551"></td>
        <td id="LC551" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zinc4jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zinc4jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} #geq 4)&quot;</span><span class="p">,</span>       <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L552" class="blob-line-num js-line-number" data-line-number="552"></td>
        <td id="LC552" class="blob-line-code js-file-line">    <span class="n">dEtaLeptons_Zinc5jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaLeptons_Zinc5jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta #eta btw lep (N_{jets} #geq 5)&quot;</span><span class="p">,</span>       <span class="n">ldEta</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L553" class="blob-line-num js-line-number" data-line-number="553"></td>
        <td id="LC553" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L554" class="blob-line-num js-line-number" data-line-number="554"></td>
        <td id="LC554" class="blob-line-code js-file-line">    <span class="n">dRLeptons_Zinc0jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dRLeptons_Zinc0jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta R btw lep (N_{jets} #geq 0)&quot;</span><span class="p">,</span>          <span class="n">ldR</span><span class="p">,</span>        <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L555" class="blob-line-num js-line-number" data-line-number="555"></td>
        <td id="LC555" class="blob-line-code js-file-line">    <span class="n">dRLeptons_Zinc1jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dRLeptons_Zinc1jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta R btw lep (N_{jets} #geq 1)&quot;</span><span class="p">,</span>          <span class="n">ldR</span><span class="p">,</span>        <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L556" class="blob-line-num js-line-number" data-line-number="556"></td>
        <td id="LC556" class="blob-line-code js-file-line">    <span class="n">dRLeptons_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dRLeptons_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta R btw lep (N_{jets} #geq 2)&quot;</span><span class="p">,</span>          <span class="n">ldR</span><span class="p">,</span>        <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L557" class="blob-line-num js-line-number" data-line-number="557"></td>
        <td id="LC557" class="blob-line-code js-file-line">    <span class="n">dRLeptons_Zinc3jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dRLeptons_Zinc3jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta R btw lep (N_{jets} #geq 3)&quot;</span><span class="p">,</span>          <span class="n">ldR</span><span class="p">,</span>        <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L558" class="blob-line-num js-line-number" data-line-number="558"></td>
        <td id="LC558" class="blob-line-code js-file-line">    <span class="n">dRLeptons_Zinc4jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dRLeptons_Zinc4jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta R btw lep (N_{jets} #geq 4)&quot;</span><span class="p">,</span>          <span class="n">ldR</span><span class="p">,</span>        <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L559" class="blob-line-num js-line-number" data-line-number="559"></td>
        <td id="LC559" class="blob-line-code js-file-line">    <span class="n">dRLeptons_Zinc5jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dRLeptons_Zinc5jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta R btw lep (N_{jets} #geq 5)&quot;</span><span class="p">,</span>          <span class="n">ldR</span><span class="p">,</span>        <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L560" class="blob-line-num js-line-number" data-line-number="560"></td>
        <td id="LC560" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L561" class="blob-line-num js-line-number" data-line-number="561"></td>
        <td id="LC561" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zexc0jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zexc0jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} = 0)&quot;</span><span class="p">,</span>            <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L562" class="blob-line-num js-line-number" data-line-number="562"></td>
        <td id="LC562" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zexc1jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zexc1jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} = 1)&quot;</span><span class="p">,</span>            <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L563" class="blob-line-num js-line-number" data-line-number="563"></td>
        <td id="LC563" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zexc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zexc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} = 2)&quot;</span><span class="p">,</span>            <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L564" class="blob-line-num js-line-number" data-line-number="564"></td>
        <td id="LC564" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zexc3jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zexc3jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} = 3)&quot;</span><span class="p">,</span>            <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L565" class="blob-line-num js-line-number" data-line-number="565"></td>
        <td id="LC565" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zexc4jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zexc4jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} = 4)&quot;</span><span class="p">,</span>            <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L566" class="blob-line-num js-line-number" data-line-number="566"></td>
        <td id="LC566" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zexc5jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zexc5jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} = 5)&quot;</span><span class="p">,</span>            <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L567" class="blob-line-num js-line-number" data-line-number="567"></td>
        <td id="LC567" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L568" class="blob-line-num js-line-number" data-line-number="568"></td>
        <td id="LC568" class="blob-line-code js-file-line">    <span class="n">genSpTLeptons_Zexc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTLeptons_Zexc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen #Delta_{pT}^{rel} lep (N_{jets} = 2)&quot;</span><span class="p">,</span>        <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L569" class="blob-line-num js-line-number" data-line-number="569"></td>
        <td id="LC569" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L570" class="blob-line-num js-line-number" data-line-number="570"></td>
        <td id="LC570" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zinc0jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zinc0jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} #geq 0)&quot;</span><span class="p">,</span>         <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L571" class="blob-line-num js-line-number" data-line-number="571"></td>
        <td id="LC571" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zinc1jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zinc1jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} #geq 1)&quot;</span><span class="p">,</span>         <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L572" class="blob-line-num js-line-number" data-line-number="572"></td>
        <td id="LC572" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zinc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} #geq 2)&quot;</span><span class="p">,</span>         <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L573" class="blob-line-num js-line-number" data-line-number="573"></td>
        <td id="LC573" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zinc3jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zinc3jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} #geq 3)&quot;</span><span class="p">,</span>         <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L574" class="blob-line-num js-line-number" data-line-number="574"></td>
        <td id="LC574" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zinc4jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zinc4jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} #geq 4)&quot;</span><span class="p">,</span>         <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L575" class="blob-line-num js-line-number" data-line-number="575"></td>
        <td id="LC575" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_Zinc5jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_Zinc5jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#Delta_{pT}^{rel} lep (N_{jets} #geq 5)&quot;</span><span class="p">,</span>         <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L576" class="blob-line-num js-line-number" data-line-number="576"></td>
        <td id="LC576" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L577" class="blob-line-num js-line-number" data-line-number="577"></td>
        <td id="LC577" class="blob-line-code js-file-line">    <span class="n">genSpTLeptons_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTLeptons_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen #Delta_{pT}^{rel} lep (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">lSpt</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L578" class="blob-line-num js-line-number" data-line-number="578"></td>
        <td id="LC578" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L579" class="blob-line-num js-line-number" data-line-number="579"></td>
        <td id="LC579" class="blob-line-code js-file-line">    <span class="n">JetsHT_Zinc1jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_Zinc1jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L580" class="blob-line-num js-line-number" data-line-number="580"></td>
        <td id="LC580" class="blob-line-code js-file-line">    <span class="n">JetsHT_1_Zinc1jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_1_Zinc1jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)1&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_1_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_1_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L581" class="blob-line-num js-line-number" data-line-number="581"></td>
        <td id="LC581" class="blob-line-code js-file-line">    <span class="n">JetsHT_2_Zinc1jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_2_Zinc1jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)2&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_2_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_2_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L582" class="blob-line-num js-line-number" data-line-number="582"></td>
        <td id="LC582" class="blob-line-code js-file-line">    <span class="n">JetsHT_3_Zinc1jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_3_Zinc1jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)3&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_3_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_3_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L583" class="blob-line-num js-line-number" data-line-number="583"></td>
        <td id="LC583" class="blob-line-code js-file-line">    <span class="n">JetsHT_4_Zinc1jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_4_Zinc1jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)4&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_4_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_4_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L584" class="blob-line-num js-line-number" data-line-number="584"></td>
        <td id="LC584" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L585" class="blob-line-num js-line-number" data-line-number="585"></td>
        <td id="LC585" class="blob-line-code js-file-line">    <span class="n">JetsHT_Zinc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_Zinc2jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L586" class="blob-line-num js-line-number" data-line-number="586"></td>
        <td id="LC586" class="blob-line-code js-file-line">    <span class="n">JetsHT_1_Zinc2jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_1_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)1&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_1_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_1_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L587" class="blob-line-num js-line-number" data-line-number="587"></td>
        <td id="LC587" class="blob-line-code js-file-line">    <span class="n">JetsHT_2_Zinc2jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_2_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)2&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_2_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_2_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L588" class="blob-line-num js-line-number" data-line-number="588"></td>
        <td id="LC588" class="blob-line-code js-file-line">    <span class="n">JetsHT_3_Zinc2jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_3_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)3&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_3_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_3_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L589" class="blob-line-num js-line-number" data-line-number="589"></td>
        <td id="LC589" class="blob-line-code js-file-line">    <span class="n">JetsHT_4_Zinc2jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_4_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)4&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_4_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_4_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L590" class="blob-line-num js-line-number" data-line-number="590"></td>
        <td id="LC590" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L591" class="blob-line-num js-line-number" data-line-number="591"></td>
        <td id="LC591" class="blob-line-code js-file-line">    <span class="n">JetsHT_Zinc3jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_Zinc3jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L592" class="blob-line-num js-line-number" data-line-number="592"></td>
        <td id="LC592" class="blob-line-code js-file-line">    <span class="n">JetsHT_1_Zinc3jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_1_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)1&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_1_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_1_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L593" class="blob-line-num js-line-number" data-line-number="593"></td>
        <td id="LC593" class="blob-line-code js-file-line">    <span class="n">JetsHT_2_Zinc3jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_2_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)2&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_2_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_2_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L594" class="blob-line-num js-line-number" data-line-number="594"></td>
        <td id="LC594" class="blob-line-code js-file-line">    <span class="n">JetsHT_3_Zinc3jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_3_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)3&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_3_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_3_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L595" class="blob-line-num js-line-number" data-line-number="595"></td>
        <td id="LC595" class="blob-line-code js-file-line">    <span class="n">JetsHT_4_Zinc3jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_4_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)4&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_4_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_4_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L596" class="blob-line-num js-line-number" data-line-number="596"></td>
        <td id="LC596" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L597" class="blob-line-num js-line-number" data-line-number="597"></td>
        <td id="LC597" class="blob-line-code js-file-line">    <span class="n">JetsHT_Zinc4jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_Zinc4jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc4jet</span><span class="p">,</span> <span class="n">jetHT_Zinc4jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L598" class="blob-line-num js-line-number" data-line-number="598"></td>
        <td id="LC598" class="blob-line-code js-file-line">    <span class="n">JetsHT_Zinc5jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_Zinc5jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc5jet</span><span class="p">,</span> <span class="n">jetHT_Zinc5jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L599" class="blob-line-num js-line-number" data-line-number="599"></td>
        <td id="LC599" class="blob-line-code js-file-line">    <span class="n">JetsHT_Zinc6jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHT_Zinc6jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc5jet</span><span class="p">,</span> <span class="n">jetHT_Zinc5jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L600" class="blob-line-num js-line-number" data-line-number="600"></td>
        <td id="LC600" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L601" class="blob-line-num js-line-number" data-line-number="601"></td>
        <td id="LC601" class="blob-line-code js-file-line">    <span class="n">genJetsHT_Zinc1jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_Zinc1jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L602" class="blob-line-num js-line-number" data-line-number="602"></td>
        <td id="LC602" class="blob-line-code js-file-line">    <span class="n">genJetsHT_1_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_1_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)1&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_1_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_1_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L603" class="blob-line-num js-line-number" data-line-number="603"></td>
        <td id="LC603" class="blob-line-code js-file-line">    <span class="n">genJetsHT_2_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_2_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)2&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_2_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_2_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L604" class="blob-line-num js-line-number" data-line-number="604"></td>
        <td id="LC604" class="blob-line-code js-file-line">    <span class="n">genJetsHT_3_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_3_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)3&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_3_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_3_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L605" class="blob-line-num js-line-number" data-line-number="605"></td>
        <td id="LC605" class="blob-line-code js-file-line">    <span class="n">genJetsHT_4_Zinc1jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_4_Zinc1jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 1)4&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_4_Zinc1jet</span><span class="p">,</span> <span class="n">jetHT_4_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L606" class="blob-line-num js-line-number" data-line-number="606"></td>
        <td id="LC606" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L607" class="blob-line-num js-line-number" data-line-number="607"></td>
        <td id="LC607" class="blob-line-code js-file-line">    <span class="n">genJetsHT_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L608" class="blob-line-num js-line-number" data-line-number="608"></td>
        <td id="LC608" class="blob-line-code js-file-line">    <span class="n">genJetsHT_1_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_1_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)1&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_1_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_1_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L609" class="blob-line-num js-line-number" data-line-number="609"></td>
        <td id="LC609" class="blob-line-code js-file-line">    <span class="n">genJetsHT_2_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_2_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)2&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_2_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_2_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L610" class="blob-line-num js-line-number" data-line-number="610"></td>
        <td id="LC610" class="blob-line-code js-file-line">    <span class="n">genJetsHT_3_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_3_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)3&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_3_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_3_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L611" class="blob-line-num js-line-number" data-line-number="611"></td>
        <td id="LC611" class="blob-line-code js-file-line">    <span class="n">genJetsHT_4_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_4_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)4&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_4_Zinc2jet</span><span class="p">,</span> <span class="n">jetHT_4_Zinc2jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L612" class="blob-line-num js-line-number" data-line-number="612"></td>
        <td id="LC612" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L613" class="blob-line-num js-line-number" data-line-number="613"></td>
        <td id="LC613" class="blob-line-code js-file-line">    <span class="n">genJetsHT_Zinc3jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_Zinc3jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L614" class="blob-line-num js-line-number" data-line-number="614"></td>
        <td id="LC614" class="blob-line-code js-file-line">    <span class="n">genJetsHT_1_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_1_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)1&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_1_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_1_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L615" class="blob-line-num js-line-number" data-line-number="615"></td>
        <td id="LC615" class="blob-line-code js-file-line">    <span class="n">genJetsHT_2_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_2_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)2&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_2_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_2_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L616" class="blob-line-num js-line-number" data-line-number="616"></td>
        <td id="LC616" class="blob-line-code js-file-line">    <span class="n">genJetsHT_3_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_3_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)3&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_3_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_3_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L617" class="blob-line-num js-line-number" data-line-number="617"></td>
        <td id="LC617" class="blob-line-code js-file-line">    <span class="n">genJetsHT_4_Zinc3jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_4_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 3)4&quot;</span><span class="p">,</span>    <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_4_Zinc3jet</span><span class="p">,</span> <span class="n">jetHT_4_Zinc3jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L618" class="blob-line-num js-line-number" data-line-number="618"></td>
        <td id="LC618" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L619" class="blob-line-num js-line-number" data-line-number="619"></td>
        <td id="LC619" class="blob-line-code js-file-line">    <span class="n">genJetsHT_Zinc4jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_Zinc4jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc4jet</span><span class="p">,</span> <span class="n">jetHT_Zinc4jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L620" class="blob-line-num js-line-number" data-line-number="620"></td>
        <td id="LC620" class="blob-line-code js-file-line">    <span class="n">genJetsHT_Zinc5jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_Zinc5jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc5jet</span><span class="p">,</span> <span class="n">jetHT_Zinc5jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L621" class="blob-line-num js-line-number" data-line-number="621"></td>
        <td id="LC621" class="blob-line-code js-file-line">    <span class="n">genJetsHT_Zinc6jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHT_Zinc6jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHT_Zinc5jet</span><span class="p">,</span> <span class="n">jetHT_Zinc5jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L622" class="blob-line-num js-line-number" data-line-number="622"></td>
        <td id="LC622" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L623" class="blob-line-num js-line-number" data-line-number="623"></td>
        <td id="LC623" class="blob-line-code js-file-line">    <span class="c1">//FirstJetPt_Zinc1jet                 = newTH1D(&quot;FirstJetPt_Zinc1jet&quot;,                 &quot;1st jet p_{T} (N_{jets} #geq 1)&quot;,             &quot;p_{T}(j_{1}) [GeV]&quot;,     nJetPt_Zinc1jet, jetPt_Zinc1jet); </span></td>
      </tr>
      <tr>
        <td id="L624" class="blob-line-num js-line-number" data-line-number="624"></td>
        <td id="LC624" class="blob-line-code js-file-line">    <span class="n">FirstJetPt_Zinc1jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPt_Zinc1jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;1st jet p_{T} (N_{jets} #geq 1 old)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>   <span class="n">jetPt_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L625" class="blob-line-num js-line-number" data-line-number="625"></td>
        <td id="LC625" class="blob-line-code js-file-line">    <span class="n">FirstJetPt_1_Zinc1jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPt_1_Zinc1jet&quot;</span><span class="p">,</span>               <span class="s">&quot;1st jet p_{T} (N_{jets} #geq 1 1)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>   <span class="n">jetPt_1_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L626" class="blob-line-num js-line-number" data-line-number="626"></td>
        <td id="LC626" class="blob-line-code js-file-line">    <span class="n">FirstJetPt_2_Zinc1jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPt_2_Zinc1jet&quot;</span><span class="p">,</span>               <span class="s">&quot;1st jet p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_2_Zinc1jet</span><span class="p">,</span> <span class="n">jetPt_2_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L627" class="blob-line-num js-line-number" data-line-number="627"></td>
        <td id="LC627" class="blob-line-code js-file-line">    <span class="n">FirstJetPt_3_Zinc1jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPt_3_Zinc1jet&quot;</span><span class="p">,</span>               <span class="s">&quot;1st jet p_{T} (N_{jets} #geq 1 3)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_3_Zinc1jet</span><span class="p">,</span> <span class="n">jetPt_3_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L628" class="blob-line-num js-line-number" data-line-number="628"></td>
        <td id="LC628" class="blob-line-code js-file-line">    <span class="n">FirstJetPt_4_Zinc1jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPt_4_Zinc1jet&quot;</span><span class="p">,</span>               <span class="s">&quot;1st jet p_{T} (N_{jets} #geq 1 4)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_4_Zinc1jet</span><span class="p">,</span> <span class="n">jetPt_4_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L629" class="blob-line-num js-line-number" data-line-number="629"></td>
        <td id="LC629" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L630" class="blob-line-num js-line-number" data-line-number="630"></td>
        <td id="LC630" class="blob-line-code js-file-line">    <span class="n">SecondJetPt_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPt_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;2nd jet p_{T} (N_{jets} #geq 2 old)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L631" class="blob-line-num js-line-number" data-line-number="631"></td>
        <td id="LC631" class="blob-line-code js-file-line">    <span class="n">SecondJetPt_1_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPt_1_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;2nd jet p_{T} (N_{jets} #geq 2 1)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_1_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_1_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L632" class="blob-line-num js-line-number" data-line-number="632"></td>
        <td id="LC632" class="blob-line-code js-file-line">    <span class="n">SecondJetPt_2_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPt_2_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;2nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_2_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_2_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L633" class="blob-line-num js-line-number" data-line-number="633"></td>
        <td id="LC633" class="blob-line-code js-file-line">    <span class="n">SecondJetPt_3_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPt_3_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;2nd jet p_{T} (N_{jets} #geq 2 3)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_3_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_3_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L634" class="blob-line-num js-line-number" data-line-number="634"></td>
        <td id="LC634" class="blob-line-code js-file-line">    <span class="n">SecondJetPt_4_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPt_4_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;2nd jet p_{T} (N_{jets} #geq 2 4)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_4_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_4_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L635" class="blob-line-num js-line-number" data-line-number="635"></td>
        <td id="LC635" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L636" class="blob-line-num js-line-number" data-line-number="636"></td>
        <td id="LC636" class="blob-line-code js-file-line">    <span class="n">ThirdJetPt_Zinc3jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPt_Zinc3jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;3rd jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L637" class="blob-line-num js-line-number" data-line-number="637"></td>
        <td id="LC637" class="blob-line-code js-file-line">    <span class="n">ThirdJetPt_1_Zinc3jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPt_1_Zinc3jet&quot;</span><span class="p">,</span>               <span class="s">&quot;3rd jet p_{T} (N_{jets} #geq 3 1)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_1_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_1_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L638" class="blob-line-num js-line-number" data-line-number="638"></td>
        <td id="LC638" class="blob-line-code js-file-line">    <span class="n">ThirdJetPt_2_Zinc3jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPt_2_Zinc3jet&quot;</span><span class="p">,</span>               <span class="s">&quot;3rd jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_2_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_2_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L639" class="blob-line-num js-line-number" data-line-number="639"></td>
        <td id="LC639" class="blob-line-code js-file-line">    <span class="n">ThirdJetPt_3_Zinc3jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPt_3_Zinc3jet&quot;</span><span class="p">,</span>               <span class="s">&quot;3rd jet p_{T} (N_{jets} #geq 3 3)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_3_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_3_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L640" class="blob-line-num js-line-number" data-line-number="640"></td>
        <td id="LC640" class="blob-line-code js-file-line">    <span class="n">ThirdJetPt_4_Zinc3jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPt_4_Zinc3jet&quot;</span><span class="p">,</span>               <span class="s">&quot;3rd jet p_{T} (N_{jets} #geq 3 4)&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_4_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_4_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L641" class="blob-line-num js-line-number" data-line-number="641"></td>
        <td id="LC641" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L642" class="blob-line-num js-line-number" data-line-number="642"></td>
        <td id="LC642" class="blob-line-code js-file-line">    <span class="n">FourthJetPt_Zinc4jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FourthJetPt_Zinc4jet&quot;</span><span class="p">,</span>                <span class="s">&quot;4th jet p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{4}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc4jet</span><span class="p">,</span> <span class="n">jetPt_Zinc4jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L643" class="blob-line-num js-line-number" data-line-number="643"></td>
        <td id="LC643" class="blob-line-code js-file-line">    <span class="n">FifthJetPt_Zinc5jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FifthJetPt_Zinc5jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;5th jet p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{5}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc5jet</span><span class="p">,</span> <span class="n">jetPt_Zinc5jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L644" class="blob-line-num js-line-number" data-line-number="644"></td>
        <td id="LC644" class="blob-line-code js-file-line">    <span class="n">SixthJetPt_Zinc6jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SixthJetPt_Zinc6jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;#geq 6th jets p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{6}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc5jet</span><span class="p">,</span> <span class="n">jetPt_Zinc5jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L645" class="blob-line-num js-line-number" data-line-number="645"></td>
        <td id="LC645" class="blob-line-code js-file-line">    <span class="n">RatioJetPt21_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;RatioJetPt21_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;ratio 2nd/1st jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{2})/p_{T}(j_{1})&quot;</span><span class="p">,</span>    <span class="mi">10</span> <span class="p">,</span> <span class="mi">0</span> <span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L646" class="blob-line-num js-line-number" data-line-number="646"></td>
        <td id="LC646" class="blob-line-code js-file-line">    <span class="n">RatioJetPt32_Zinc3jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;RatioJetPt32_Zinc3jet&quot;</span><span class="p">,</span>                <span class="s">&quot;ratio 3rd/2nd jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{3})/p_{T}(j_{2})&quot;</span><span class="p">,</span>    <span class="mi">10</span> <span class="p">,</span> <span class="mi">0</span> <span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L647" class="blob-line-num js-line-number" data-line-number="647"></td>
        <td id="LC647" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L648" class="blob-line-num js-line-number" data-line-number="648"></td>
        <td id="LC648" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L649" class="blob-line-num js-line-number" data-line-number="649"></td>
        <td id="LC649" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L650" class="blob-line-num js-line-number" data-line-number="650"></td>
        <td id="LC650" class="blob-line-code js-file-line">    <span class="c1">//genFirstJetPt_Zinc1jet              = newTH1D(&quot;genFirstJetPt_Zinc1jet&quot;,              &quot;gen 1st jet p_{T} (N_{jets} #geq 1)&quot;,         &quot;p_{T}(j_{1}) [GeV]&quot;,     nJetPt_Zinc1jet, jetPt_Zinc1jet);</span></td>
      </tr>
      <tr>
        <td id="L651" class="blob-line-num js-line-number" data-line-number="651"></td>
        <td id="LC651" class="blob-line-code js-file-line">    <span class="n">genFirstJetPt_Zinc1jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetPt_Zinc1jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen 1st jet p_{T} (N_{jets} #geq 1 old)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>   <span class="n">jetPt_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L652" class="blob-line-num js-line-number" data-line-number="652"></td>
        <td id="LC652" class="blob-line-code js-file-line">    <span class="n">genFirstJetPt_1_Zinc1jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetPt_1_Zinc1jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 1st jet p_{T} (N_{jets} #geq 1 1)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>   <span class="n">jetPt_1_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L653" class="blob-line-num js-line-number" data-line-number="653"></td>
        <td id="LC653" class="blob-line-code js-file-line">    <span class="n">genFirstJetPt_2_Zinc1jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetPt_2_Zinc1jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 1st jet p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_2_Zinc1jet</span><span class="p">,</span> <span class="n">jetPt_2_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L654" class="blob-line-num js-line-number" data-line-number="654"></td>
        <td id="LC654" class="blob-line-code js-file-line">    <span class="n">genFirstJetPt_3_Zinc1jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetPt_3_Zinc1jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 1st jet p_{T} (N_{jets} #geq 1 3)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_3_Zinc1jet</span><span class="p">,</span> <span class="n">jetPt_3_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L655" class="blob-line-num js-line-number" data-line-number="655"></td>
        <td id="LC655" class="blob-line-code js-file-line">    <span class="n">genFirstJetPt_4_Zinc1jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetPt_4_Zinc1jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 1st jet p_{T} (N_{jets} #geq 1 4)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_4_Zinc1jet</span><span class="p">,</span> <span class="n">jetPt_4_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L656" class="blob-line-num js-line-number" data-line-number="656"></td>
        <td id="LC656" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L657" class="blob-line-num js-line-number" data-line-number="657"></td>
        <td id="LC657" class="blob-line-code js-file-line">    <span class="n">genSecondJetPt_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetPt_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen 2nd jet p_{T} (N_{jets} #geq 2 old)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L658" class="blob-line-num js-line-number" data-line-number="658"></td>
        <td id="LC658" class="blob-line-code js-file-line">    <span class="n">genSecondJetPt_1_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetPt_1_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen 2nd jet p_{T} (N_{jets} #geq 2 1)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_1_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_1_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L659" class="blob-line-num js-line-number" data-line-number="659"></td>
        <td id="LC659" class="blob-line-code js-file-line">    <span class="n">genSecondJetPt_2_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetPt_2_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen 2nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_2_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_2_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L660" class="blob-line-num js-line-number" data-line-number="660"></td>
        <td id="LC660" class="blob-line-code js-file-line">    <span class="n">genSecondJetPt_3_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetPt_3_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen 2nd jet p_{T} (N_{jets} #geq 2 3)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_3_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_3_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L661" class="blob-line-num js-line-number" data-line-number="661"></td>
        <td id="LC661" class="blob-line-code js-file-line">    <span class="n">genSecondJetPt_4_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetPt_4_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen 2nd jet p_{T} (N_{jets} #geq 2 4)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_4_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_4_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L662" class="blob-line-num js-line-number" data-line-number="662"></td>
        <td id="LC662" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L663" class="blob-line-num js-line-number" data-line-number="663"></td>
        <td id="LC663" class="blob-line-code js-file-line">    <span class="n">genThirdJetPt_Zinc3jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPt_Zinc3jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen 3rd jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L664" class="blob-line-num js-line-number" data-line-number="664"></td>
        <td id="LC664" class="blob-line-code js-file-line">    <span class="n">genThirdJetPt_1_Zinc3jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPt_1_Zinc3jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 3rd jet p_{T} (N_{jets} #geq 3 1)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_1_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_1_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L665" class="blob-line-num js-line-number" data-line-number="665"></td>
        <td id="LC665" class="blob-line-code js-file-line">    <span class="n">genThirdJetPt_2_Zinc3jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPt_2_Zinc3jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 3rd jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_2_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_2_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L666" class="blob-line-num js-line-number" data-line-number="666"></td>
        <td id="LC666" class="blob-line-code js-file-line">    <span class="n">genThirdJetPt_3_Zinc3jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPt_3_Zinc3jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 3rd jet p_{T} (N_{jets} #geq 3 3)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_3_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_3_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L667" class="blob-line-num js-line-number" data-line-number="667"></td>
        <td id="LC667" class="blob-line-code js-file-line">    <span class="n">genThirdJetPt_4_Zinc3jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPt_4_Zinc3jet&quot;</span><span class="p">,</span>            <span class="s">&quot;gen 3rd jet p_{T} (N_{jets} #geq 3 4)&quot;</span><span class="p">,</span>       <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_4_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_4_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L668" class="blob-line-num js-line-number" data-line-number="668"></td>
        <td id="LC668" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L669" class="blob-line-num js-line-number" data-line-number="669"></td>
        <td id="LC669" class="blob-line-code js-file-line">    <span class="n">genFourthJetPt_Zinc4jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFourthJetPt_Zinc4jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen 4th jet p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{4}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc4jet</span><span class="p">,</span> <span class="n">jetPt_Zinc4jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L670" class="blob-line-num js-line-number" data-line-number="670"></td>
        <td id="LC670" class="blob-line-code js-file-line">    <span class="n">genFifthJetPt_Zinc5jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFifthJetPt_Zinc5jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen 5th jet p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{5}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc5jet</span><span class="p">,</span> <span class="n">jetPt_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L671" class="blob-line-num js-line-number" data-line-number="671"></td>
        <td id="LC671" class="blob-line-code js-file-line">    <span class="n">genSixthJetPt_Zinc6jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSixthJetPt_Zinc6jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen #geq 6th jets p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>   <span class="s">&quot;p_{T}(j_{6}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc5jet</span><span class="p">,</span> <span class="n">jetPt_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L672" class="blob-line-num js-line-number" data-line-number="672"></td>
        <td id="LC672" class="blob-line-code js-file-line">    <span class="n">genRatioJetPt21_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genRatioJetPt21_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen ratio 2nd/1st jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{2})/p_{T}(j_{1})&quot;</span><span class="p">,</span>    <span class="mi">10</span> <span class="p">,</span> <span class="mi">0</span> <span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L673" class="blob-line-num js-line-number" data-line-number="673"></td>
        <td id="LC673" class="blob-line-code js-file-line">    <span class="n">genRatioJetPt32_Zinc3jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genRatioJetPt32_Zinc3jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen ratio 3rd/2nd jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>         <span class="s">&quot;p_{T}(j_{3})/p_{T}(j_{2})&quot;</span><span class="p">,</span>    <span class="mi">10</span> <span class="p">,</span> <span class="mi">0</span> <span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L674" class="blob-line-num js-line-number" data-line-number="674"></td>
        <td id="LC674" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L675" class="blob-line-num js-line-number" data-line-number="675"></td>
        <td id="LC675" class="blob-line-code js-file-line">    <span class="n">FirstJetPt_Zexc1jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPt_Zexc1jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;1st jet p_{T} (N_{jets} = 1)&quot;</span><span class="p">,</span>                <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L676" class="blob-line-num js-line-number" data-line-number="676"></td>
        <td id="LC676" class="blob-line-code js-file-line">    <span class="n">SecondJetPt_Zexc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPt_Zexc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;2nd jet p_{T} (N_{jets} = 2)&quot;</span><span class="p">,</span>                <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L677" class="blob-line-num js-line-number" data-line-number="677"></td>
        <td id="LC677" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L678" class="blob-line-num js-line-number" data-line-number="678"></td>
        <td id="LC678" class="blob-line-code js-file-line">    <span class="n">genFirstJetPt_Zexc1jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetPt_Zexc1jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen 1st jet p_{T} (N_{jets} = 1)&quot;</span><span class="p">,</span>            <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L679" class="blob-line-num js-line-number" data-line-number="679"></td>
        <td id="LC679" class="blob-line-code js-file-line">    <span class="n">genSecondJetPt_Zexc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetPt_Zexc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen 2nd jet p_{T} (N_{jets} = 2)&quot;</span><span class="p">,</span>            <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L680" class="blob-line-num js-line-number" data-line-number="680"></td>
        <td id="LC680" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L681" class="blob-line-num js-line-number" data-line-number="681"></td>
        <td id="LC681" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L682" class="blob-line-num js-line-number" data-line-number="682"></td>
        <td id="LC682" class="blob-line-code js-file-line">    <span class="n">FirstHighestJetPt_Zinc1jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstHighestJetPt_Zinc1jet&quot;</span><span class="p">,</span>          <span class="s">&quot;1st Highest jet p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L683" class="blob-line-num js-line-number" data-line-number="683"></td>
        <td id="LC683" class="blob-line-code js-file-line">    <span class="n">FirstHighestJetPt_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstHighestJetPt_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;1st Highest jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L684" class="blob-line-num js-line-number" data-line-number="684"></td>
        <td id="LC684" class="blob-line-code js-file-line">    <span class="n">FirstHighestJetPt_Zinc3jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstHighestJetPt_Zinc3jet&quot;</span><span class="p">,</span>          <span class="s">&quot;1st Highest jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L685" class="blob-line-num js-line-number" data-line-number="685"></td>
        <td id="LC685" class="blob-line-code js-file-line">    <span class="n">FirstHighestJetPt_Zinc4jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstHighestJetPt_Zinc4jet&quot;</span><span class="p">,</span>          <span class="s">&quot;1st Highest jet p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L686" class="blob-line-num js-line-number" data-line-number="686"></td>
        <td id="LC686" class="blob-line-code js-file-line">    <span class="n">FirstHighestJetPt_Zinc5jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstHighestJetPt_Zinc5jet&quot;</span><span class="p">,</span>          <span class="s">&quot;1st Highest jet p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L687" class="blob-line-num js-line-number" data-line-number="687"></td>
        <td id="LC687" class="blob-line-code js-file-line">    <span class="n">FirstHighestJetPt_Zinc6jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstHighestJetPt_Zinc6jet&quot;</span><span class="p">,</span>          <span class="s">&quot;1st Highest jet p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L688" class="blob-line-num js-line-number" data-line-number="688"></td>
        <td id="LC688" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L689" class="blob-line-num js-line-number" data-line-number="689"></td>
        <td id="LC689" class="blob-line-code js-file-line">    <span class="n">genFirstHighestJetPt_Zinc1jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstHighestJetPt_Zinc1jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 1st Highest jet p_{T} (N_{jets} #geq 1)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L690" class="blob-line-num js-line-number" data-line-number="690"></td>
        <td id="LC690" class="blob-line-code js-file-line">    <span class="n">genFirstHighestJetPt_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstHighestJetPt_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 1st Highest jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L691" class="blob-line-num js-line-number" data-line-number="691"></td>
        <td id="LC691" class="blob-line-code js-file-line">    <span class="n">genFirstHighestJetPt_Zinc3jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstHighestJetPt_Zinc3jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 1st Highest jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L692" class="blob-line-num js-line-number" data-line-number="692"></td>
        <td id="LC692" class="blob-line-code js-file-line">    <span class="n">genFirstHighestJetPt_Zinc4jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstHighestJetPt_Zinc4jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 1st Highest jet p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L693" class="blob-line-num js-line-number" data-line-number="693"></td>
        <td id="LC693" class="blob-line-code js-file-line">    <span class="n">genFirstHighestJetPt_Zinc5jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstHighestJetPt_Zinc5jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 1st Highest jet p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L694" class="blob-line-num js-line-number" data-line-number="694"></td>
        <td id="LC694" class="blob-line-code js-file-line">    <span class="n">genFirstHighestJetPt_Zinc6jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstHighestJetPt_Zinc6jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 1st Highest jet p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>    <span class="n">jetPt_Zinc1jet</span><span class="p">);</span>  </td>
      </tr>
      <tr>
        <td id="L695" class="blob-line-num js-line-number" data-line-number="695"></td>
        <td id="LC695" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L696" class="blob-line-num js-line-number" data-line-number="696"></td>
        <td id="LC696" class="blob-line-code js-file-line">    <span class="n">SecondHighestJetPt_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondHighestJetPt_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;2nd Highest jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L697" class="blob-line-num js-line-number" data-line-number="697"></td>
        <td id="LC697" class="blob-line-code js-file-line">    <span class="n">SecondHighestJetPt_Zinc3jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondHighestJetPt_Zinc3jet&quot;</span><span class="p">,</span>         <span class="s">&quot;2nd Highest jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L698" class="blob-line-num js-line-number" data-line-number="698"></td>
        <td id="LC698" class="blob-line-code js-file-line">    <span class="n">SecondHighestJetPt_Zinc4jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondHighestJetPt_Zinc4jet&quot;</span><span class="p">,</span>         <span class="s">&quot;2nd Highest jet p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L699" class="blob-line-num js-line-number" data-line-number="699"></td>
        <td id="LC699" class="blob-line-code js-file-line">    <span class="n">SecondHighestJetPt_Zinc5jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondHighestJetPt_Zinc5jet&quot;</span><span class="p">,</span>         <span class="s">&quot;2nd Highest jet p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L700" class="blob-line-num js-line-number" data-line-number="700"></td>
        <td id="LC700" class="blob-line-code js-file-line">    <span class="n">SecondHighestJetPt_Zinc6jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondHighestJetPt_Zinc6jet&quot;</span><span class="p">,</span>         <span class="s">&quot;2nd Highest jet p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L701" class="blob-line-num js-line-number" data-line-number="701"></td>
        <td id="LC701" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L702" class="blob-line-num js-line-number" data-line-number="702"></td>
        <td id="LC702" class="blob-line-code js-file-line">    <span class="n">genSecondHighestJetPt_Zinc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondHighestJetPt_Zinc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen 2nd Highest jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L703" class="blob-line-num js-line-number" data-line-number="703"></td>
        <td id="LC703" class="blob-line-code js-file-line">    <span class="n">genSecondHighestJetPt_Zinc3jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondHighestJetPt_Zinc3jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen 2nd Highest jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L704" class="blob-line-num js-line-number" data-line-number="704"></td>
        <td id="LC704" class="blob-line-code js-file-line">    <span class="n">genSecondHighestJetPt_Zinc4jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondHighestJetPt_Zinc4jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen 2nd Highest jet p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L705" class="blob-line-num js-line-number" data-line-number="705"></td>
        <td id="LC705" class="blob-line-code js-file-line">    <span class="n">genSecondHighestJetPt_Zinc5jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondHighestJetPt_Zinc5jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen 2nd Highest jet p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L706" class="blob-line-num js-line-number" data-line-number="706"></td>
        <td id="LC706" class="blob-line-code js-file-line">    <span class="n">genSecondHighestJetPt_Zinc6jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondHighestJetPt_Zinc6jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen 2nd Highest jet p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc2jet</span><span class="p">,</span> <span class="n">jetPt_Zinc2jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L707" class="blob-line-num js-line-number" data-line-number="707"></td>
        <td id="LC707" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L708" class="blob-line-num js-line-number" data-line-number="708"></td>
        <td id="LC708" class="blob-line-code js-file-line">    <span class="n">ThirdHighestJetPt_Zinc3jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdHighestJetPt_Zinc3jet&quot;</span><span class="p">,</span>          <span class="s">&quot;3rd Highest jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L709" class="blob-line-num js-line-number" data-line-number="709"></td>
        <td id="LC709" class="blob-line-code js-file-line">    <span class="n">ThirdHighestJetPt_Zinc4jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdHighestJetPt_Zinc4jet&quot;</span><span class="p">,</span>          <span class="s">&quot;3rd Highest jet p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L710" class="blob-line-num js-line-number" data-line-number="710"></td>
        <td id="LC710" class="blob-line-code js-file-line">    <span class="n">ThirdHighestJetPt_Zinc5jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdHighestJetPt_Zinc5jet&quot;</span><span class="p">,</span>          <span class="s">&quot;3rd Highest jet p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L711" class="blob-line-num js-line-number" data-line-number="711"></td>
        <td id="LC711" class="blob-line-code js-file-line">    <span class="n">ThirdHighestJetPt_Zinc6jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdHighestJetPt_Zinc6jet&quot;</span><span class="p">,</span>          <span class="s">&quot;3rd Highest jet p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span>     <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L712" class="blob-line-num js-line-number" data-line-number="712"></td>
        <td id="LC712" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L713" class="blob-line-num js-line-number" data-line-number="713"></td>
        <td id="LC713" class="blob-line-code js-file-line">    <span class="n">genThirdHighestJetPt_Zinc3jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdHighestJetPt_Zinc3jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 3rd Highest jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L714" class="blob-line-num js-line-number" data-line-number="714"></td>
        <td id="LC714" class="blob-line-code js-file-line">    <span class="n">genThirdHighestJetPt_Zinc4jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdHighestJetPt_Zinc4jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 3rd Highest jet p_{T} (N_{jets} #geq 4)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L715" class="blob-line-num js-line-number" data-line-number="715"></td>
        <td id="LC715" class="blob-line-code js-file-line">    <span class="n">genThirdHighestJetPt_Zinc5jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdHighestJetPt_Zinc5jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 3rd Highest jet p_{T} (N_{jets} #geq 5)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L716" class="blob-line-num js-line-number" data-line-number="716"></td>
        <td id="LC716" class="blob-line-code js-file-line">    <span class="n">genThirdHighestJetPt_Zinc6jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdHighestJetPt_Zinc6jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen 3rd Highest jet p_{T} (N_{jets} #geq 6)&quot;</span><span class="p">,</span> <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L717" class="blob-line-num js-line-number" data-line-number="717"></td>
        <td id="LC717" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L718" class="blob-line-num js-line-number" data-line-number="718"></td>
        <td id="LC718" class="blob-line-code js-file-line">    <span class="n">AllJetPt_Zinc1jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPt_Zinc1jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;All jets (N_{jets} #geq 1)&quot;</span><span class="p">,</span>                  <span class="s">&quot;p_{T}(jets) [GeV]&quot;</span><span class="p">,</span>     <span class="mi">80</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L719" class="blob-line-num js-line-number" data-line-number="719"></td>
        <td id="LC719" class="blob-line-code js-file-line">    <span class="n">AllJetPt_Zinc2jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPt_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;All jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                  <span class="s">&quot;p_{T}(jets) [GeV]&quot;</span><span class="p">,</span>     <span class="mi">80</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L720" class="blob-line-num js-line-number" data-line-number="720"></td>
        <td id="LC720" class="blob-line-code js-file-line">    <span class="n">AllJetPt_Zinc3jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPt_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;All jets (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                  <span class="s">&quot;p_{T}(jets) [GeV]&quot;</span><span class="p">,</span>     <span class="mi">80</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L721" class="blob-line-num js-line-number" data-line-number="721"></td>
        <td id="LC721" class="blob-line-code js-file-line">    <span class="n">AllJetPt_Zinc4jet</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPt_Zinc4jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;All jets (N_{jets} #geq 4)&quot;</span><span class="p">,</span>                  <span class="s">&quot;p_{T}(jets) [GeV]&quot;</span><span class="p">,</span>     <span class="mi">80</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">400</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L722" class="blob-line-num js-line-number" data-line-number="722"></td>
        <td id="LC722" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L723" class="blob-line-num js-line-number" data-line-number="723"></td>
        <td id="LC723" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L724" class="blob-line-num js-line-number" data-line-number="724"></td>
        <td id="LC724" class="blob-line-code js-file-line">    <span class="n">hPtEtaBackJet_Zexc1jet</span>              <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;PtEtaBackJet_Zexc1jet&quot;</span><span class="p">,</span>              <span class="s">&quot;p_{T} #eta (N_{jets} = 1)&quot;</span><span class="p">,</span>       <span class="n">nJetPtEta_Zinc1jet</span><span class="p">,</span> <span class="n">jetPtEta_Zinc1jet</span>   <span class="p">,</span>      <span class="mi">12</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L725" class="blob-line-num js-line-number" data-line-number="725"></td>
        <td id="LC725" class="blob-line-code js-file-line">    <span class="n">hPtEtaBackJetMVA_Zexc1jet</span>           <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;PtEtaBackJetMVA_Zexc1jet&quot;</span><span class="p">,</span>           <span class="s">&quot;p_{T} #eta (N_{jets} = 1)&quot;</span><span class="p">,</span>       <span class="n">nJetPtEta_Zinc1jet</span><span class="p">,</span> <span class="n">jetPtEta_Zinc1jet</span>   <span class="p">,</span>      <span class="mi">12</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L726" class="blob-line-num js-line-number" data-line-number="726"></td>
        <td id="LC726" class="blob-line-code js-file-line">    <span class="n">FirstJetPtEta_Zinc1jet</span>              <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;FirstJetPtEta_Zinc1jet&quot;</span><span class="p">,</span>              <span class="s">&quot;1st jet p_{T} #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>       <span class="n">nJetPtEta_Zinc1jet</span><span class="p">,</span> <span class="n">jetPtEta_Zinc1jet</span>   <span class="p">,</span>      <span class="mi">12</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L727" class="blob-line-num js-line-number" data-line-number="727"></td>
        <td id="LC727" class="blob-line-code js-file-line">    <span class="n">SecondJetPtEta_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;SecondJetPtEta_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;2nd jet p_{T} #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>       <span class="n">nJetPtEta_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEta_Zinc2jet</span>   <span class="p">,</span>       <span class="mi">8</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L728" class="blob-line-num js-line-number" data-line-number="728"></td>
        <td id="LC728" class="blob-line-code js-file-line">    <span class="n">ThirdJetPtEta_Zinc3jet</span>              <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;ThirdJetPtEta_Zinc3jet&quot;</span><span class="p">,</span>              <span class="s">&quot;3rd jet p_{T} #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>       <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span>	        <span class="p">,</span>       <span class="mi">6</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L729" class="blob-line-num js-line-number" data-line-number="729"></td>
        <td id="LC729" class="blob-line-code js-file-line">    <span class="n">FourthJetPtEta_Zinc4jet</span>             <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;FourthJetPtEta_Zinc4jet&quot;</span><span class="p">,</span>             <span class="s">&quot;4th jet p_{T} #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>       <span class="n">nJetPt_Zinc4jet</span><span class="p">,</span> <span class="n">jetPt_Zinc4jet</span>         <span class="p">,</span>       <span class="mi">4</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L730" class="blob-line-num js-line-number" data-line-number="730"></td>
        <td id="LC730" class="blob-line-code js-file-line">    <span class="n">FifthJetPtEta_Zinc5jet</span>              <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;FifthJetPtEta_Zinc5jet&quot;</span><span class="p">,</span>              <span class="s">&quot;5th jet p_{T} #eta (N_{jets} #geq 5)&quot;</span><span class="p">,</span>       <span class="n">nJetPt_Zinc5jet</span><span class="p">,</span> <span class="n">jetPt_Zinc5jet</span>         <span class="p">,</span>       <span class="mi">2</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L731" class="blob-line-num js-line-number" data-line-number="731"></td>
        <td id="LC731" class="blob-line-code js-file-line">    <span class="n">SixthJetPtEta_Zinc6jet</span>              <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;SixthJetPtEta_Zinc6jet&quot;</span><span class="p">,</span>              <span class="s">&quot;6th jet p_{T} #eta (N_{jets} #geq 6)&quot;</span><span class="p">,</span>       <span class="n">nJetPt_Zinc5jet</span><span class="p">,</span> <span class="n">jetPt_Zinc5jet</span>         <span class="p">,</span>       <span class="mi">2</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L732" class="blob-line-num js-line-number" data-line-number="732"></td>
        <td id="LC732" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L733" class="blob-line-num js-line-number" data-line-number="733"></td>
        <td id="LC733" class="blob-line-code js-file-line">    <span class="n">genFirstJetPtEta_Zinc1jet</span>           <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;genFirstJetPtEta_Zinc1jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen 1st jet p_{T} #eta (N_{jets} #geq 1)&quot;</span><span class="p">,</span>    <span class="n">nJetPtEta_Zinc1jet</span><span class="p">,</span> <span class="n">jetPtEta_Zinc1jet</span>  <span class="p">,</span>      <span class="mi">12</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L734" class="blob-line-num js-line-number" data-line-number="734"></td>
        <td id="LC734" class="blob-line-code js-file-line">    <span class="n">genSecondJetPtEta_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;genSecondJetPtEta_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen 2nd jet p_{T} #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>    <span class="n">nJetPtEta_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEta_Zinc2jet</span>  <span class="p">,</span>       <span class="mi">8</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L735" class="blob-line-num js-line-number" data-line-number="735"></td>
        <td id="LC735" class="blob-line-code js-file-line">    <span class="n">genThirdJetPtEta_Zinc3jet</span>           <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;genThirdJetPtEta_Zinc3jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen 3rd jet p_{T} #eta (N_{jets} #geq 3)&quot;</span><span class="p">,</span>    <span class="n">nJetPt_Zinc3jet</span><span class="p">,</span> <span class="n">jetPt_Zinc3jet</span>        <span class="p">,</span>       <span class="mi">6</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L736" class="blob-line-num js-line-number" data-line-number="736"></td>
        <td id="LC736" class="blob-line-code js-file-line">    <span class="n">genFourthJetPtEta_Zinc4jet</span>          <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;genFourthJetPtEta_Zinc4jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen 4th jet p_{T} #eta (N_{jets} #geq 4)&quot;</span><span class="p">,</span>    <span class="n">nJetPt_Zinc4jet</span><span class="p">,</span> <span class="n">jetPt_Zinc4jet</span>        <span class="p">,</span>       <span class="mi">4</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L737" class="blob-line-num js-line-number" data-line-number="737"></td>
        <td id="LC737" class="blob-line-code js-file-line">    <span class="n">genFifthJetPtEta_Zinc5jet</span>           <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;genFifthJetPtEta_Zinc5jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen 5th jet p_{T} #eta (N_{jets} #geq 5)&quot;</span><span class="p">,</span>    <span class="n">nJetPt_Zinc5jet</span><span class="p">,</span> <span class="n">jetPt_Zinc5jet</span>        <span class="p">,</span>       <span class="mi">2</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L738" class="blob-line-num js-line-number" data-line-number="738"></td>
        <td id="LC738" class="blob-line-code js-file-line">    <span class="n">genSixthJetPtEta_Zinc6jet</span>           <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;genSixthJetPtEta_Zinc6jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen 6th jet p_{T} #eta (N_{jets} #geq 6)&quot;</span><span class="p">,</span>    <span class="n">nJetPt_Zinc5jet</span><span class="p">,</span> <span class="n">jetPt_Zinc5jet</span>        <span class="p">,</span>       <span class="mi">2</span>  <span class="p">,</span>  <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L739" class="blob-line-num js-line-number" data-line-number="739"></td>
        <td id="LC739" class="blob-line-code js-file-line">    <span class="k">if</span> <span class="p">(</span> <span class="n">doWJets</span> <span class="p">)</span> <span class="n">ZNGoodJets_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJets_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L740" class="blob-line-num js-line-number" data-line-number="740"></td>
        <td id="LC740" class="blob-line-code js-file-line">    <span class="k">else</span> <span class="n">ZNGoodJets_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJets_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">7.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L741" class="blob-line-num js-line-number" data-line-number="741"></td>
        <td id="LC741" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L742" class="blob-line-num js-line-number" data-line-number="742"></td>
        <td id="LC742" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L743" class="blob-line-num js-line-number" data-line-number="743"></td>
        <td id="LC743" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L744" class="blob-line-num js-line-number" data-line-number="744"></td>
        <td id="LC744" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L745" class="blob-line-num js-line-number" data-line-number="745"></td>
        <td id="LC745" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L746" class="blob-line-num js-line-number" data-line-number="746"></td>
        <td id="LC746" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L747" class="blob-line-num js-line-number" data-line-number="747"></td>
        <td id="LC747" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L748" class="blob-line-num js-line-number" data-line-number="748"></td>
        <td id="LC748" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L749" class="blob-line-num js-line-number" data-line-number="749"></td>
        <td id="LC749" class="blob-line-code js-file-line">    <span class="k">if</span> <span class="p">(</span> <span class="n">doWJets</span> <span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L750" class="blob-line-num js-line-number" data-line-number="750"></td>
        <td id="LC750" class="blob-line-code js-file-line">        <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span><span class="s">&quot;#geq 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L751" class="blob-line-num js-line-number" data-line-number="751"></td>
        <td id="LC751" class="blob-line-code js-file-line">        <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;#geq 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L752" class="blob-line-num js-line-number" data-line-number="752"></td>
        <td id="LC752" class="blob-line-code js-file-line">        <span class="n">ZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;#geq 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L753" class="blob-line-num js-line-number" data-line-number="753"></td>
        <td id="LC753" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L754" class="blob-line-num js-line-number" data-line-number="754"></td>
        <td id="LC754" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L755" class="blob-line-num js-line-number" data-line-number="755"></td>
        <td id="LC755" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L756" class="blob-line-num js-line-number" data-line-number="756"></td>
        <td id="LC756" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span> <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;ZNGoodJetsNVtx_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;NVtx vs Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">,</span> <span class="mi">45</span><span class="p">,</span> <span class="mf">0.5</span><span class="p">,</span> <span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L757" class="blob-line-num js-line-number" data-line-number="757"></td>
        <td id="LC757" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L758" class="blob-line-num js-line-number" data-line-number="758"></td>
        <td id="LC758" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L759" class="blob-line-num js-line-number" data-line-number="759"></td>
        <td id="LC759" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L760" class="blob-line-num js-line-number" data-line-number="760"></td>
        <td id="LC760" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L761" class="blob-line-num js-line-number" data-line-number="761"></td>
        <td id="LC761" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L762" class="blob-line-num js-line-number" data-line-number="762"></td>
        <td id="LC762" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L763" class="blob-line-num js-line-number" data-line-number="763"></td>
        <td id="LC763" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L764" class="blob-line-num js-line-number" data-line-number="764"></td>
        <td id="LC764" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L765" class="blob-line-num js-line-number" data-line-number="765"></td>
        <td id="LC765" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;= 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L766" class="blob-line-num js-line-number" data-line-number="766"></td>
        <td id="LC766" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;= 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L767" class="blob-line-num js-line-number" data-line-number="767"></td>
        <td id="LC767" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsNVtx_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;= 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L768" class="blob-line-num js-line-number" data-line-number="768"></td>
        <td id="LC768" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L769" class="blob-line-num js-line-number" data-line-number="769"></td>
        <td id="LC769" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJets_Zinc&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (incl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L770" class="blob-line-num js-line-number" data-line-number="770"></td>
        <td id="LC770" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;#geq 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L771" class="blob-line-num js-line-number" data-line-number="771"></td>
        <td id="LC771" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;#geq 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L772" class="blob-line-num js-line-number" data-line-number="772"></td>
        <td id="LC772" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;#geq 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L773" class="blob-line-num js-line-number" data-line-number="773"></td>
        <td id="LC773" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;#geq 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L774" class="blob-line-num js-line-number" data-line-number="774"></td>
        <td id="LC774" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;#geq 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L775" class="blob-line-num js-line-number" data-line-number="775"></td>
        <td id="LC775" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;#geq 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L776" class="blob-line-num js-line-number" data-line-number="776"></td>
        <td id="LC776" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;#geq 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L777" class="blob-line-num js-line-number" data-line-number="777"></td>
        <td id="LC777" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;#geq 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L778" class="blob-line-num js-line-number" data-line-number="778"></td>
        <td id="LC778" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;#geq 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L779" class="blob-line-num js-line-number" data-line-number="779"></td>
        <td id="LC779" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;#geq 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L780" class="blob-line-num js-line-number" data-line-number="780"></td>
        <td id="LC780" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;#geq 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L781" class="blob-line-num js-line-number" data-line-number="781"></td>
        <td id="LC781" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L782" class="blob-line-num js-line-number" data-line-number="782"></td>
        <td id="LC782" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJets_Zexc_check&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (incl.) CHECK&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">7.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L783" class="blob-line-num js-line-number" data-line-number="783"></td>
        <td id="LC783" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="s">&quot;#geq 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L784" class="blob-line-num js-line-number" data-line-number="784"></td>
        <td id="LC784" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span><span class="s">&quot;#geq 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L785" class="blob-line-num js-line-number" data-line-number="785"></td>
        <td id="LC785" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span><span class="s">&quot;#geq 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L786" class="blob-line-num js-line-number" data-line-number="786"></td>
        <td id="LC786" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span><span class="s">&quot;#geq 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L787" class="blob-line-num js-line-number" data-line-number="787"></td>
        <td id="LC787" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span><span class="s">&quot;#geq 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L788" class="blob-line-num js-line-number" data-line-number="788"></td>
        <td id="LC788" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span><span class="s">&quot;#geq 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L789" class="blob-line-num js-line-number" data-line-number="789"></td>
        <td id="LC789" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span><span class="s">&quot;#geq 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L790" class="blob-line-num js-line-number" data-line-number="790"></td>
        <td id="LC790" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_check</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span><span class="s">&quot;#geq 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L791" class="blob-line-num js-line-number" data-line-number="791"></td>
        <td id="LC791" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L792" class="blob-line-num js-line-number" data-line-number="792"></td>
        <td id="LC792" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJets_Zexc_NoWeight&quot;</span><span class="p">,</span><span class="s">&quot;Unweighted jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">7.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L793" class="blob-line-num js-line-number" data-line-number="793"></td>
        <td id="LC793" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L794" class="blob-line-num js-line-number" data-line-number="794"></td>
        <td id="LC794" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span><span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L795" class="blob-line-num js-line-number" data-line-number="795"></td>
        <td id="LC795" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span><span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L796" class="blob-line-num js-line-number" data-line-number="796"></td>
        <td id="LC796" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span><span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L797" class="blob-line-num js-line-number" data-line-number="797"></td>
        <td id="LC797" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span><span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L798" class="blob-line-num js-line-number" data-line-number="798"></td>
        <td id="LC798" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span><span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L799" class="blob-line-num js-line-number" data-line-number="799"></td>
        <td id="LC799" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span><span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L800" class="blob-line-num js-line-number" data-line-number="800"></td>
        <td id="LC800" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zexc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span><span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L801" class="blob-line-num js-line-number" data-line-number="801"></td>
        <td id="LC801" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L802" class="blob-line-num js-line-number" data-line-number="802"></td>
        <td id="LC802" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJets_Zinc_NoWeight&quot;</span><span class="p">,</span><span class="s">&quot;Unweighted jet Counter (incl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">7.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L803" class="blob-line-num js-line-number" data-line-number="803"></td>
        <td id="LC803" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="s">&quot;#geq 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L804" class="blob-line-num js-line-number" data-line-number="804"></td>
        <td id="LC804" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span><span class="s">&quot;#geq 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L805" class="blob-line-num js-line-number" data-line-number="805"></td>
        <td id="LC805" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span><span class="s">&quot;#geq 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L806" class="blob-line-num js-line-number" data-line-number="806"></td>
        <td id="LC806" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span><span class="s">&quot;#geq 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L807" class="blob-line-num js-line-number" data-line-number="807"></td>
        <td id="LC807" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span><span class="s">&quot;#geq 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L808" class="blob-line-num js-line-number" data-line-number="808"></td>
        <td id="LC808" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span><span class="s">&quot;#geq 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L809" class="blob-line-num js-line-number" data-line-number="809"></td>
        <td id="LC809" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span><span class="s">&quot;#geq 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L810" class="blob-line-num js-line-number" data-line-number="810"></td>
        <td id="LC810" class="blob-line-code js-file-line">    <span class="n">ZNGoodJets_Zinc_NoWeight</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span><span class="s">&quot;#geq 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L811" class="blob-line-num js-line-number" data-line-number="811"></td>
        <td id="LC811" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L812" class="blob-line-num js-line-number" data-line-number="812"></td>
        <td id="LC812" class="blob-line-code js-file-line">    <span class="c1">//DPS histograms</span></td>
      </tr>
      <tr>
        <td id="L813" class="blob-line-num js-line-number" data-line-number="813"></td>
        <td id="LC813" class="blob-line-code js-file-line">    <span class="c1">//binning </span></td>
      </tr>
      <tr>
        <td id="L814" class="blob-line-num js-line-number" data-line-number="814"></td>
        <td id="LC814" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="n">nbinSpt</span><span class="o">=</span><span class="mi">21</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L815" class="blob-line-num js-line-number" data-line-number="815"></td>
        <td id="LC815" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">binSpt</span><span class="p">[</span><span class="mi">22</span><span class="p">]</span><span class="o">=</span><span class="p">{</span><span class="mi">0</span><span class="p">,</span><span class="mf">0.05</span><span class="p">,</span><span class="mf">0.1</span><span class="p">,</span><span class="mf">0.15</span><span class="p">,</span><span class="mf">0.2</span><span class="p">,</span><span class="mf">0.25</span><span class="p">,</span><span class="mf">0.3</span><span class="p">,</span><span class="mf">0.35</span><span class="p">,</span><span class="mf">0.4</span><span class="p">,</span><span class="mf">.45</span><span class="p">,</span><span class="mf">.5</span><span class="p">,</span><span class="mf">.55</span><span class="p">,</span><span class="mf">.6</span><span class="p">,</span><span class="mf">.65</span><span class="p">,</span><span class="mf">0.7</span><span class="p">,</span><span class="mf">0.75</span><span class="p">,</span><span class="mf">0.8</span><span class="p">,</span><span class="mf">0.85</span><span class="p">,</span><span class="mf">0.9</span><span class="p">,</span><span class="mf">0.94</span><span class="p">,</span><span class="mf">0.98</span><span class="p">,</span><span class="mi">1</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L816" class="blob-line-num js-line-number" data-line-number="816"></td>
        <td id="LC816" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L817" class="blob-line-num js-line-number" data-line-number="817"></td>
        <td id="LC817" class="blob-line-code js-file-line">    <span class="c1">//-- jets and Z</span></td>
      </tr>
      <tr>
        <td id="L818" class="blob-line-num js-line-number" data-line-number="818"></td>
        <td id="LC818" class="blob-line-code js-file-line">    <span class="n">TwoJetsPtDiff_Zexc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TwoJetsPtDiff_Zexc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;pT diff of the two highest jet (N_{jets} = 2)&quot;</span><span class="p">,</span>                                <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L819" class="blob-line-num js-line-number" data-line-number="819"></td>
        <td id="LC819" class="blob-line-code js-file-line">    <span class="n">genTwoJetsPtDiff_Zexc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genTwoJetsPtDiff_Zexc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;gen pT diff of the two highest jet (N_{jets} = 2)&quot;</span><span class="p">,</span>                            <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L820" class="blob-line-num js-line-number" data-line-number="820"></td>
        <td id="LC820" class="blob-line-code js-file-line">    <span class="n">JetsMass_Zexc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsMass_Zexc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;2Jets Invariant Mass (N_{jets} = 2)&quot;</span><span class="p">,</span>                                          <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L821" class="blob-line-num js-line-number" data-line-number="821"></td>
        <td id="LC821" class="blob-line-code js-file-line">    <span class="n">genJetsMass_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsMass_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen 2Jets Invariant Mass (N_{jets} = 2)&quot;</span><span class="p">,</span>                                      <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L822" class="blob-line-num js-line-number" data-line-number="822"></td>
        <td id="LC822" class="blob-line-code js-file-line">    <span class="n">ptBal_Zexc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBal_Zexc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                          <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L823" class="blob-line-num js-line-number" data-line-number="823"></td>
        <td id="LC823" class="blob-line-code js-file-line">    <span class="n">genptBal_Zexc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genptBal_Zexc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                      <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L824" class="blob-line-num js-line-number" data-line-number="824"></td>
        <td id="LC824" class="blob-line-code js-file-line">    <span class="n">dPhiJets_Zexc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJets_Zexc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;#Delta#phi btwn jets (N_{jets} = 2)&quot;</span><span class="p">,</span>                                          <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L825" class="blob-line-num js-line-number" data-line-number="825"></td>
        <td id="LC825" class="blob-line-code js-file-line">    <span class="n">gendPhiJets_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJets_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen #Delta#phi btwn jets (N_{jets} = 2)&quot;</span><span class="p">,</span>                                      <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L826" class="blob-line-num js-line-number" data-line-number="826"></td>
        <td id="LC826" class="blob-line-code js-file-line">    <span class="n">dEtaJets_Zexc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaJets_Zexc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;#Delta#eta btwn jets (N_{jets} = 2)&quot;</span><span class="p">,</span>                                          <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">48</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L827" class="blob-line-num js-line-number" data-line-number="827"></td>
        <td id="LC827" class="blob-line-code js-file-line">    <span class="n">gendEtaJets_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaJets_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen #Delta#eta btwn jets (N_{jets} = 2)&quot;</span><span class="p">,</span>                                      <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">48</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L828" class="blob-line-num js-line-number" data-line-number="828"></td>
        <td id="LC828" class="blob-line-code js-file-line">    <span class="n">dEtaFirstJetZ_Zexc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaFirstJetZ_Zexc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;#Delta#eta btwn Jet_{1} and Z (N_{jets} = 2)&quot;</span><span class="p">,</span>                                 <span class="s">&quot;#Delta#eta(j_{1}Z)&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L829" class="blob-line-num js-line-number" data-line-number="829"></td>
        <td id="LC829" class="blob-line-code js-file-line">    <span class="n">gendEtaFirstJetZ_Zexc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaFirstJetZ_Zexc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;gen #Delta#eta btwn Jet_{1} and Z (N_{jets} = 2)&quot;</span><span class="p">,</span>                             <span class="s">&quot;#Delta#eta(j_{1}Z)&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L830" class="blob-line-num js-line-number" data-line-number="830"></td>
        <td id="LC830" class="blob-line-code js-file-line">    <span class="n">dEtaSecondJetZ_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaSecondJetZ_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta#eta btwn Jet_{2} and Z (N_{jets} = 2)&quot;</span><span class="p">,</span>                                 <span class="s">&quot;#Delta#eta(j_{2}Z)&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L831" class="blob-line-num js-line-number" data-line-number="831"></td>
        <td id="LC831" class="blob-line-code js-file-line">    <span class="n">gendEtaSecondJetZ_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaSecondJetZ_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta#eta btwn Jet_{2} and Z (N_{jets} = 2)&quot;</span><span class="p">,</span>                             <span class="s">&quot;#Delta#eta(j_{2}Z)&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L832" class="blob-line-num js-line-number" data-line-number="832"></td>
        <td id="LC832" class="blob-line-code js-file-line">    <span class="n">dEtaJet1Plus2Z_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaJet1Plus2Z_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta#eta btwn jets and Z (N_{jets} = 2)&quot;</span><span class="p">,</span>                                    <span class="s">&quot;#Delta#eta(j_{12}Z)&quot;</span><span class="p">,</span>           <span class="mi">120</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L833" class="blob-line-num js-line-number" data-line-number="833"></td>
        <td id="LC833" class="blob-line-code js-file-line">    <span class="n">gendEtaJet1Plus2Z_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaJet1Plus2Z_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta#eta btwn jets and Z (N_{jets} = 2)&quot;</span><span class="p">,</span>                                <span class="s">&quot;#Delta#eta(j_{12}Z)&quot;</span><span class="p">,</span>           <span class="mi">120</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L834" class="blob-line-num js-line-number" data-line-number="834"></td>
        <td id="LC834" class="blob-line-code js-file-line">    <span class="n">PHI_Zexc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_Zexc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#phi: Angle btwn the two subsystems planes (N_{jets} = 2)&quot;</span><span class="p">,</span>                    <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>                 <span class="mi">25</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L835" class="blob-line-num js-line-number" data-line-number="835"></td>
        <td id="LC835" class="blob-line-code js-file-line">    <span class="n">genPHI_Zexc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_Zexc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes (N_{jets} = 2)&quot;</span><span class="p">,</span>                <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>                 <span class="mi">25</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L836" class="blob-line-num js-line-number" data-line-number="836"></td>
        <td id="LC836" class="blob-line-code js-file-line">    <span class="n">PHI_T_Zexc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_T_Zexc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta S Angle btwn lep and jet pair in T-plane (N_{jets} = 2)&quot;</span><span class="p">,</span>            <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L837" class="blob-line-num js-line-number" data-line-number="837"></td>
        <td id="LC837" class="blob-line-code js-file-line">    <span class="n">genPHI_T_Zexc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_T_Zexc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen #Delta S Angle btwn lep and jet pair in T-plane (N_{jets} = 2)&quot;</span><span class="p">,</span>        <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L838" class="blob-line-num js-line-number" data-line-number="838"></td>
        <td id="LC838" class="blob-line-code js-file-line">    <span class="n">SpT_Zexc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_Zexc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta_{pT}^{rel} lep and jets combined (N_{jets} = 2)&quot;</span><span class="p">,</span>                   <span class="n">Spt</span><span class="p">,</span>    <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L839" class="blob-line-num js-line-number" data-line-number="839"></td>
        <td id="LC839" class="blob-line-code js-file-line">    <span class="n">genSpT_Zexc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_Zexc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen #Delta_{pT}^{rel} lep and jets combined (N_{jets} = 2)&quot;</span><span class="p">,</span>               <span class="n">Spt</span><span class="p">,</span>    <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L840" class="blob-line-num js-line-number" data-line-number="840"></td>
        <td id="LC840" class="blob-line-code js-file-line">    <span class="n">SpTJets_Zexc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJets_Zexc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;#Delta_{pT}^{rel} jets (N_{jets} = 2)&quot;</span><span class="p">,</span>                                  <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L841" class="blob-line-num js-line-number" data-line-number="841"></td>
        <td id="LC841" class="blob-line-code js-file-line">    <span class="n">genSpTJets_Zexc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJets_Zexc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen #Delta_{pT}^{rel} jets (N_{jets} = 2)&quot;</span><span class="p">,</span>                              <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L842" class="blob-line-num js-line-number" data-line-number="842"></td>
        <td id="LC842" class="blob-line-code js-file-line">    <span class="n">SPhi_Zexc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_Zexc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;S_{#phi} lep and jets combined (N_{jets} = 2)&quot;</span><span class="p">,</span>                            <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L843" class="blob-line-num js-line-number" data-line-number="843"></td>
        <td id="LC843" class="blob-line-code js-file-line">    <span class="n">genSPhi_Zexc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_Zexc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen S_{#phi} lep and jets combined (N_{jets} = 2)&quot;</span><span class="p">,</span>                        <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L844" class="blob-line-num js-line-number" data-line-number="844"></td>
        <td id="LC844" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L845" class="blob-line-num js-line-number" data-line-number="845"></td>
        <td id="LC845" class="blob-line-code js-file-line">    <span class="n">TwoJetsPtDiff_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TwoJetsPtDiff_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                             <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L846" class="blob-line-num js-line-number" data-line-number="846"></td>
        <td id="LC846" class="blob-line-code js-file-line">    <span class="n">genTwoJetsPtDiff_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genTwoJetsPtDiff_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;gen pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                         <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L847" class="blob-line-num js-line-number" data-line-number="847"></td>
        <td id="LC847" class="blob-line-code js-file-line">    <span class="n">BestTwoJetsPtDiff_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestTwoJetsPtDiff_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;Best pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                        <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L848" class="blob-line-num js-line-number" data-line-number="848"></td>
        <td id="LC848" class="blob-line-code js-file-line">    <span class="n">genBestTwoJetsPtDiff_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestTwoJetsPtDiff_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen Best pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                    <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L849" class="blob-line-num js-line-number" data-line-number="849"></td>
        <td id="LC849" class="blob-line-code js-file-line">    <span class="n">JetsMass_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsMass_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L850" class="blob-line-num js-line-number" data-line-number="850"></td>
        <td id="LC850" class="blob-line-code js-file-line">    <span class="n">genJetsMass_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsMass_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen 2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L851" class="blob-line-num js-line-number" data-line-number="851"></td>
        <td id="LC851" class="blob-line-code js-file-line">    <span class="n">BestJetsMass_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestJetsMass_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;Best 2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                  <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L852" class="blob-line-num js-line-number" data-line-number="852"></td>
        <td id="LC852" class="blob-line-code js-file-line">    <span class="n">genBestJetsMass_Zinc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestJetsMass_Zinc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen Best 2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                              <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L853" class="blob-line-num js-line-number" data-line-number="853"></td>
        <td id="LC853" class="blob-line-code js-file-line">    <span class="n">ptBal_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBal_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                       <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L854" class="blob-line-num js-line-number" data-line-number="854"></td>
        <td id="LC854" class="blob-line-code js-file-line">    <span class="n">genptBal_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genptBal_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                   <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L855" class="blob-line-num js-line-number" data-line-number="855"></td>
        <td id="LC855" class="blob-line-code js-file-line">    <span class="n">dPhiJets_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJets_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;#Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L856" class="blob-line-num js-line-number" data-line-number="856"></td>
        <td id="LC856" class="blob-line-code js-file-line">    <span class="n">gendPhiJets_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJets_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen #Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L857" class="blob-line-num js-line-number" data-line-number="857"></td>
        <td id="LC857" class="blob-line-code js-file-line">    <span class="n">BestdPhiJets_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestdPhiJets_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;Best #Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                  <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L858" class="blob-line-num js-line-number" data-line-number="858"></td>
        <td id="LC858" class="blob-line-code js-file-line">    <span class="n">genBestdPhiJets_Zinc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestdPhiJets_Zinc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen Best #Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                              <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L859" class="blob-line-num js-line-number" data-line-number="859"></td>
        <td id="LC859" class="blob-line-code js-file-line">    <span class="n">dEtaJets_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaJets_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;#Delta#eta btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">48</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L860" class="blob-line-num js-line-number" data-line-number="860"></td>
        <td id="LC860" class="blob-line-code js-file-line">    <span class="n">gendEtaJets_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaJets_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen #Delta#eta btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">48</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L861" class="blob-line-num js-line-number" data-line-number="861"></td>
        <td id="LC861" class="blob-line-code js-file-line">    <span class="n">dEtaFirstJetZ_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaFirstJetZ_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;#Delta#eta btwn Jet_{1} and Z (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                              <span class="s">&quot;#Delta#eta(j_{1}Z)&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L862" class="blob-line-num js-line-number" data-line-number="862"></td>
        <td id="LC862" class="blob-line-code js-file-line">    <span class="n">gendEtaFirstJetZ_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaFirstJetZ_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;gen #Delta#eta btwn Jet_{1} and Z (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                          <span class="s">&quot;#Delta#eta(j_{1}Z)&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L863" class="blob-line-num js-line-number" data-line-number="863"></td>
        <td id="LC863" class="blob-line-code js-file-line">    <span class="n">dEtaSecondJetZ_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaSecondJetZ_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta#eta btwn Jet_{2} and Z (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                              <span class="s">&quot;#Delta#eta(j_{2}Z)&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L864" class="blob-line-num js-line-number" data-line-number="864"></td>
        <td id="LC864" class="blob-line-code js-file-line">    <span class="n">gendEtaSecondJetZ_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaSecondJetZ_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta#eta btwn Jet_{2} and Z (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                          <span class="s">&quot;#Delta#eta(j_{2}Z)&quot;</span><span class="p">,</span>           <span class="mi">120</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L865" class="blob-line-num js-line-number" data-line-number="865"></td>
        <td id="LC865" class="blob-line-code js-file-line">    <span class="n">dEtaJet1Plus2Z_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaJet1Plus2Z_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta#eta btwn jets and Z (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                 <span class="s">&quot;#Delta#eta(j_{12}Z)&quot;</span><span class="p">,</span>          <span class="mi">120</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L866" class="blob-line-num js-line-number" data-line-number="866"></td>
        <td id="LC866" class="blob-line-code js-file-line">    <span class="n">gendEtaJet1Plus2Z_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaJet1Plus2Z_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta#eta btwn jets and Z (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                             <span class="s">&quot;#Delta#eta(j_{12}Z)&quot;</span><span class="p">,</span>          <span class="mi">120</span><span class="p">,</span> <span class="o">-</span><span class="mi">6</span><span class="p">,</span> <span class="mi">6</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L867" class="blob-line-num js-line-number" data-line-number="867"></td>
        <td id="LC867" class="blob-line-code js-file-line">    <span class="n">PHI_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#phi: Angle btwn the two subsystems planes (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                 <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>                 <span class="mi">25</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L868" class="blob-line-num js-line-number" data-line-number="868"></td>
        <td id="LC868" class="blob-line-code js-file-line">    <span class="n">genPHI_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>                 <span class="mi">25</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L869" class="blob-line-num js-line-number" data-line-number="869"></td>
        <td id="LC869" class="blob-line-code js-file-line">    <span class="n">BestPHI_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestPHI_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;Best #phi: Angle btwn the two subsystems planes (N_{jets} #geq 2)&quot;</span><span class="p">,</span>            <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>                 <span class="mi">25</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L870" class="blob-line-num js-line-number" data-line-number="870"></td>
        <td id="LC870" class="blob-line-code js-file-line">    <span class="n">genBestPHI_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestPHI_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen Best #phi: Angle btwn the two subsystems planes (N_{jets} #geq 2)&quot;</span><span class="p">,</span>        <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>                 <span class="mi">25</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L871" class="blob-line-num js-line-number" data-line-number="871"></td>
        <td id="LC871" class="blob-line-code js-file-line">    <span class="n">PHI_T_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_T_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;#Delta S Angle btwn lep and jet pair in T-plane (N_{jets} #geq 2)&quot;</span><span class="p">,</span>         <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L872" class="blob-line-num js-line-number" data-line-number="872"></td>
        <td id="LC872" class="blob-line-code js-file-line">    <span class="n">genPHI_T_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_T_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;gen #Delta S Angle btwn lep and jet pair in T-plane (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L873" class="blob-line-num js-line-number" data-line-number="873"></td>
        <td id="LC873" class="blob-line-code js-file-line">    <span class="n">BestPHI_T_Zinc2jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestPHI_T_Zinc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;Best #Delta S Angle btwn lep and jet pair in T-plane (N_{jets} #geq 2)&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L874" class="blob-line-num js-line-number" data-line-number="874"></td>
        <td id="LC874" class="blob-line-code js-file-line">    <span class="n">genBestPHI_T_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestPHI_T_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;gen Best #Delta S Angle btwn lep and jet pair in T-plane (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L875" class="blob-line-num js-line-number" data-line-number="875"></td>
        <td id="LC875" class="blob-line-code js-file-line">    <span class="n">SpT_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta_{pT}^{rel} lep and jets combined (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                 <span class="n">Spt</span><span class="p">,</span>    <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L876" class="blob-line-num js-line-number" data-line-number="876"></td>
        <td id="LC876" class="blob-line-code js-file-line">    <span class="n">genSpT_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;gen #Delta_{pT}^{rel} lep and jets combined (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="n">Spt</span><span class="p">,</span>    <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L877" class="blob-line-num js-line-number" data-line-number="877"></td>
        <td id="LC877" class="blob-line-code js-file-line">    <span class="n">BestSpT_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestSpT_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;Best #Delta_{pT}^{rel} lep and jets combined (N_{jets} #geq 2)&quot;</span><span class="p">,</span>            <span class="n">Spt</span><span class="p">,</span>    <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L878" class="blob-line-num js-line-number" data-line-number="878"></td>
        <td id="LC878" class="blob-line-code js-file-line">    <span class="n">genBestSpT_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestSpT_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen Best #Delta_{pT}^{rel} lep and jets combined (N_{jets} #geq 2)&quot;</span><span class="p">,</span>         <span class="n">Spt</span><span class="p">,</span>    <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L879" class="blob-line-num js-line-number" data-line-number="879"></td>
        <td id="LC879" class="blob-line-code js-file-line">    <span class="n">SpTJets_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJets_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;#Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L880" class="blob-line-num js-line-number" data-line-number="880"></td>
        <td id="LC880" class="blob-line-code js-file-line">    <span class="n">genSpTJets_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJets_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;gen #Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                            <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L881" class="blob-line-num js-line-number" data-line-number="881"></td>
        <td id="LC881" class="blob-line-code js-file-line">    <span class="n">BestSpTJets_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestSpTJets_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;Best #Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                           <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L882" class="blob-line-num js-line-number" data-line-number="882"></td>
        <td id="LC882" class="blob-line-code js-file-line">    <span class="n">genBestSpTJets_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestSpTJets_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen Best #Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                       <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">20</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L883" class="blob-line-num js-line-number" data-line-number="883"></td>
        <td id="LC883" class="blob-line-code js-file-line">    <span class="n">SPhi_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_Zinc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;S_{#phi} lep and jets combined (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                          <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L884" class="blob-line-num js-line-number" data-line-number="884"></td>
        <td id="LC884" class="blob-line-code js-file-line">    <span class="n">genSPhi_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;gen S_{#phi} lep and jets combined (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                      <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L885" class="blob-line-num js-line-number" data-line-number="885"></td>
        <td id="LC885" class="blob-line-code js-file-line">    <span class="n">BestSPhi_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestSPhi_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;Best S_{#phi} lep and jets combined (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                     <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L886" class="blob-line-num js-line-number" data-line-number="886"></td>
        <td id="LC886" class="blob-line-code js-file-line">    <span class="n">genBestSPhi_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestSPhi_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;gen Best S_{#phi} lep and jets combined (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                 <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L887" class="blob-line-num js-line-number" data-line-number="887"></td>
        <td id="LC887" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L888" class="blob-line-num js-line-number" data-line-number="888"></td>
        <td id="LC888" class="blob-line-code js-file-line">    <span class="c1">//-- low Z pT</span></td>
      </tr>
      <tr>
        <td id="L889" class="blob-line-num js-line-number" data-line-number="889"></td>
        <td id="LC889" class="blob-line-code js-file-line">    <span class="n">TwoJetsPtDiff_LowPt_Zexc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TwoJetsPtDiff_LowPt_Zexc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;pT diff of the two highest jet at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                  <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L890" class="blob-line-num js-line-number" data-line-number="890"></td>
        <td id="LC890" class="blob-line-code js-file-line">    <span class="n">genTwoJetsPtDiff_LowPt_Zexc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genTwoJetsPtDiff_LowPt_Zexc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen pT diff of the two highest jet at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>          <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L891" class="blob-line-num js-line-number" data-line-number="891"></td>
        <td id="LC891" class="blob-line-code js-file-line">    <span class="n">JetsMass_LowPt_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsMass_LowPt_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;2Jets Invariant Mass at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                            <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L892" class="blob-line-num js-line-number" data-line-number="892"></td>
        <td id="LC892" class="blob-line-code js-file-line">    <span class="n">genJetsMass_LowPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsMass_LowPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen 2Jets Invariant Mass at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                        <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L893" class="blob-line-num js-line-number" data-line-number="893"></td>
        <td id="LC893" class="blob-line-code js-file-line">    <span class="n">ptBal_LowPt_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBal_LowPt_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;Vectorial pT sum: Z_{pT} + DiJet_{pT} at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>            <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L894" class="blob-line-num js-line-number" data-line-number="894"></td>
        <td id="LC894" class="blob-line-code js-file-line">    <span class="n">genptBal_LowPt_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genptBal_LowPt_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen Vectorial pT sum: Z_{pT} + DiJet_{pT} at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>        <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L895" class="blob-line-num js-line-number" data-line-number="895"></td>
        <td id="LC895" class="blob-line-code js-file-line">    <span class="n">dPhiJets_LowPt_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJets_LowPt_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta#phi btwn jets at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                            <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L896" class="blob-line-num js-line-number" data-line-number="896"></td>
        <td id="LC896" class="blob-line-code js-file-line">    <span class="n">gendPhiJets_LowPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJets_LowPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta#phi btwn jets at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                        <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L897" class="blob-line-num js-line-number" data-line-number="897"></td>
        <td id="LC897" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_LowPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_LowPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta#phi btwn leptons at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                         <span class="n">ldPhi</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L898" class="blob-line-num js-line-number" data-line-number="898"></td>
        <td id="LC898" class="blob-line-code js-file-line">    <span class="n">gendPhiLeptons_LowPt_Zexc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiLeptons_LowPt_Zexc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen #Delta#phi btwn leptons at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                     <span class="n">ldPhi</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L899" class="blob-line-num js-line-number" data-line-number="899"></td>
        <td id="LC899" class="blob-line-code js-file-line">    <span class="n">PHI_LowPt_Zexc2jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_LowPt_Zexc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;#phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>      <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L900" class="blob-line-num js-line-number" data-line-number="900"></td>
        <td id="LC900" class="blob-line-code js-file-line">    <span class="n">genPHI_LowPt_Zexc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_LowPt_Zexc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L901" class="blob-line-num js-line-number" data-line-number="901"></td>
        <td id="LC901" class="blob-line-code js-file-line">    <span class="n">PHI_T_LowPt_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_T_LowPt_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;#Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L902" class="blob-line-num js-line-number" data-line-number="902"></td>
        <td id="LC902" class="blob-line-code js-file-line">    <span class="n">genPHI_T_LowPt_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_T_LowPt_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen #Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L903" class="blob-line-num js-line-number" data-line-number="903"></td>
        <td id="LC903" class="blob-line-code js-file-line">    <span class="n">SpT_LowPt_Zexc2jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>     <span class="n">Spt</span><span class="p">,</span>    <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L904" class="blob-line-num js-line-number" data-line-number="904"></td>
        <td id="LC904" class="blob-line-code js-file-line">    <span class="n">genSpT_LowPt_Zexc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;gen #Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span> <span class="n">Spt</span><span class="p">,</span>    <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L905" class="blob-line-num js-line-number" data-line-number="905"></td>
        <td id="LC905" class="blob-line-code js-file-line">    <span class="n">SpTJets_LowPt_Zexc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJets_LowPt_Zexc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;#Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                    <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L906" class="blob-line-num js-line-number" data-line-number="906"></td>
        <td id="LC906" class="blob-line-code js-file-line">    <span class="n">genSpTJets_LowPt_Zexc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJets_LowPt_Zexc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;gen #Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L907" class="blob-line-num js-line-number" data-line-number="907"></td>
        <td id="LC907" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_LowPt_Zexc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_LowPt_Zexc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;#Delta_{pT}^{rel} leptons at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                 <span class="n">lSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L908" class="blob-line-num js-line-number" data-line-number="908"></td>
        <td id="LC908" class="blob-line-code js-file-line">    <span class="n">genSpTLeptons_LowPt_Zexc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTLeptons_LowPt_Zexc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;gen #Delta_{pT}^{rel} leptons at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>             <span class="n">lSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L909" class="blob-line-num js-line-number" data-line-number="909"></td>
        <td id="LC909" class="blob-line-code js-file-line">    <span class="n">SPhi_LowPt_Zexc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_LowPt_Zexc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>             <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L910" class="blob-line-num js-line-number" data-line-number="910"></td>
        <td id="LC910" class="blob-line-code js-file-line">    <span class="n">genSPhi_LowPt_Zexc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_LowPt_Zexc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;gen S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>         <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L911" class="blob-line-num js-line-number" data-line-number="911"></td>
        <td id="LC911" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L912" class="blob-line-num js-line-number" data-line-number="912"></td>
        <td id="LC912" class="blob-line-code js-file-line">    <span class="n">TwoJetsPtDiff_LowPt_Zinc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TwoJetsPtDiff_LowPt_Zinc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;pT diff of the two highest jet at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                              <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>   <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L913" class="blob-line-num js-line-number" data-line-number="913"></td>
        <td id="LC913" class="blob-line-code js-file-line">    <span class="n">genTwoJetsPtDiff_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genTwoJetsPtDiff_LowPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen pT diff of the two highest jet at low Z_{pT}  (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                     <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>   <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L914" class="blob-line-num js-line-number" data-line-number="914"></td>
        <td id="LC914" class="blob-line-code js-file-line">    <span class="n">BestTwoJetsPtDiff_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestTwoJetsPtDiff_LowPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;Best pT diff of the two highest jet at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                   <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>   <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L915" class="blob-line-num js-line-number" data-line-number="915"></td>
        <td id="LC915" class="blob-line-code js-file-line">    <span class="n">genBestTwoJetsPtDiff_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestTwoJetsPtDiff_LowPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen Best pT diff of the two highest jet at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>         <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>   <span class="mi">10</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L916" class="blob-line-num js-line-number" data-line-number="916"></td>
        <td id="LC916" class="blob-line-code js-file-line">    <span class="n">JetsMass_LowPt_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsMass_LowPt_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;2Jets Invariant Mass at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                        <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L917" class="blob-line-num js-line-number" data-line-number="917"></td>
        <td id="LC917" class="blob-line-code js-file-line">    <span class="n">genJetsMass_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsMass_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen 2Jets Invariant Mass at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                    <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L918" class="blob-line-num js-line-number" data-line-number="918"></td>
        <td id="LC918" class="blob-line-code js-file-line">    <span class="n">BestJetsMass_LowPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestJetsMass_LowPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;Best 2Jets Invariant Mass at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L919" class="blob-line-num js-line-number" data-line-number="919"></td>
        <td id="LC919" class="blob-line-code js-file-line">    <span class="n">genBestJetsMass_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestJetsMass_LowPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen Best 2Jets Invariant Mass at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                             <span class="n">Mjj</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">625</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L920" class="blob-line-num js-line-number" data-line-number="920"></td>
        <td id="LC920" class="blob-line-code js-file-line">    <span class="n">ptBal_LowPt_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBal_LowPt_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;Vectorial pT sum: Z_{pT} + DiJet_{pT} at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                        <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L921" class="blob-line-num js-line-number" data-line-number="921"></td>
        <td id="LC921" class="blob-line-code js-file-line">    <span class="n">genptBal_LowPt_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genptBal_LowPt_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen Vectorial pT sum: Z_{pT} + DiJet_{pT} at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                    <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L922" class="blob-line-num js-line-number" data-line-number="922"></td>
        <td id="LC922" class="blob-line-code js-file-line">    <span class="n">dPhiJets_LowPt_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJets_LowPt_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta#phi btwn jets at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                        <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L923" class="blob-line-num js-line-number" data-line-number="923"></td>
        <td id="LC923" class="blob-line-code js-file-line">    <span class="n">gendPhiJets_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJets_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen#Delta#phi btwn jets at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                     <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L924" class="blob-line-num js-line-number" data-line-number="924"></td>
        <td id="LC924" class="blob-line-code js-file-line">    <span class="n">BestdPhiJets_LowPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestdPhiJets_LowPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;Best #Delta#phi btwn jets at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L925" class="blob-line-num js-line-number" data-line-number="925"></td>
        <td id="LC925" class="blob-line-code js-file-line">    <span class="n">genBestdPhiJets_LowPt_Zinc2jet</span><span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestdPhiJets_LowPt_Zinc2jet&quot;</span><span class="p">,</span><span class="s">&quot;gen Best #Delta#phi btwn jets at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                               <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L926" class="blob-line-num js-line-number" data-line-number="926"></td>
        <td id="LC926" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta #phi btwn leptons at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                    <span class="n">ldPhi</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L927" class="blob-line-num js-line-number" data-line-number="927"></td>
        <td id="LC927" class="blob-line-code js-file-line">    <span class="n">gendPhiLeptons_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiLeptons_LowPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen #Delta #phi btwn leptons at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                <span class="n">ldPhi</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L928" class="blob-line-num js-line-number" data-line-number="928"></td>
        <td id="LC928" class="blob-line-code js-file-line">    <span class="n">PHI_LowPt_Zinc2jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_LowPt_Zinc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;#phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                  <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>        <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L929" class="blob-line-num js-line-number" data-line-number="929"></td>
        <td id="LC929" class="blob-line-code js-file-line">    <span class="n">genPHI_LowPt_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_LowPt_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>        <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L930" class="blob-line-num js-line-number" data-line-number="930"></td>
        <td id="LC930" class="blob-line-code js-file-line">    <span class="n">BestPHI_LowPt_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestPHI_LowPt_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;Best #phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>        <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L931" class="blob-line-num js-line-number" data-line-number="931"></td>
        <td id="LC931" class="blob-line-code js-file-line">    <span class="n">genBestPHI_LowPt_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestPHI_LowPt_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;gen Best #phi: Angle btwn the two subsystems planes at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>         <span class="s">&quot;#phi(j_{12}Z)&quot;</span><span class="p">,</span>        <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L932" class="blob-line-num js-line-number" data-line-number="932"></td>
        <td id="LC932" class="blob-line-code js-file-line">    <span class="n">PHI_T_LowPt_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_T_LowPt_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;#Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>          <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>    <span class="mi">10</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L933" class="blob-line-num js-line-number" data-line-number="933"></td>
        <td id="LC933" class="blob-line-code js-file-line">    <span class="n">genPHI_T_LowPt_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_T_LowPt_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen #Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>      <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>    <span class="mi">10</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L934" class="blob-line-num js-line-number" data-line-number="934"></td>
        <td id="LC934" class="blob-line-code js-file-line">    <span class="n">BestPHI_T_LowPt_Zinc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestPHI_T_LowPt_Zinc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;Best #Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>    <span class="mi">10</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L935" class="blob-line-num js-line-number" data-line-number="935"></td>
        <td id="LC935" class="blob-line-code js-file-line">    <span class="n">genBestPHI_T_LowPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestPHI_T_LowPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen Best #Delta S Angle btwn lepton and jet pair in T-plane at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span> <span class="s">&quot;#Delta S(j_{12}Z)&quot;</span><span class="p">,</span>    <span class="mi">10</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L936" class="blob-line-num js-line-number" data-line-number="936"></td>
        <td id="LC936" class="blob-line-code js-file-line">    <span class="n">SpT_LowPt_Zinc2jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                 <span class="n">Spt</span><span class="p">,</span>    <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L937" class="blob-line-num js-line-number" data-line-number="937"></td>
        <td id="LC937" class="blob-line-code js-file-line">    <span class="n">genSpT_LowPt_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;gen #Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="n">Spt</span><span class="p">,</span>    <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L938" class="blob-line-num js-line-number" data-line-number="938"></td>
        <td id="LC938" class="blob-line-code js-file-line">    <span class="n">BestSpT_LowPt_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;Best #Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>            <span class="n">Spt</span><span class="p">,</span>    <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L939" class="blob-line-num js-line-number" data-line-number="939"></td>
        <td id="LC939" class="blob-line-code js-file-line">    <span class="n">genBestSpT_LowPt_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;gen Best #Delta_{pT}^{rel} leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>        <span class="n">Spt</span><span class="p">,</span>    <span class="mi">25</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L940" class="blob-line-num js-line-number" data-line-number="940"></td>
        <td id="LC940" class="blob-line-code js-file-line">    <span class="n">SpTJets_LowPt_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJets_LowPt_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;#Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L941" class="blob-line-num js-line-number" data-line-number="941"></td>
        <td id="LC941" class="blob-line-code js-file-line">    <span class="n">genSpTJets_LowPt_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJets_LowPt_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;gen #Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                            <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L942" class="blob-line-num js-line-number" data-line-number="942"></td>
        <td id="LC942" class="blob-line-code js-file-line">    <span class="n">BestSpTJets_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestSpTJets_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;Best #Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                           <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L943" class="blob-line-num js-line-number" data-line-number="943"></td>
        <td id="LC943" class="blob-line-code js-file-line">    <span class="n">genBestSpTJets_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestSpTJets_LowPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen Best #Delta_{pT}^{rel} jets at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                       <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L944" class="blob-line-num js-line-number" data-line-number="944"></td>
        <td id="LC944" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_LowPt_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_LowPt_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;#Delta_{pT}^{rel} leptons at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                             <span class="n">lSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L945" class="blob-line-num js-line-number" data-line-number="945"></td>
        <td id="LC945" class="blob-line-code js-file-line">    <span class="n">genSpTLeptons_LowPt_Zinc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTLeptons_LowPt_Zinc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;gen #Delta_{pT}^{rel} leptons at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                         <span class="n">lSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L946" class="blob-line-num js-line-number" data-line-number="946"></td>
        <td id="LC946" class="blob-line-code js-file-line">    <span class="n">SPhi_LowPt_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_LowPt_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                         <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L947" class="blob-line-num js-line-number" data-line-number="947"></td>
        <td id="LC947" class="blob-line-code js-file-line">    <span class="n">genSPhi_LowPt_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_LowPt_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;gen S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                     <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L948" class="blob-line-num js-line-number" data-line-number="948"></td>
        <td id="LC948" class="blob-line-code js-file-line">    <span class="n">BestSPhi_LowPt_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BestSPhi_LowPt_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;Best S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                    <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L949" class="blob-line-num js-line-number" data-line-number="949"></td>
        <td id="LC949" class="blob-line-code js-file-line">    <span class="n">genBestSPhi_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genBestSPhi_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen Best S_{#phi}: leptons and jets combined at low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                <span class="n">Sphi</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L950" class="blob-line-num js-line-number" data-line-number="950"></td>
        <td id="LC950" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L951" class="blob-line-num js-line-number" data-line-number="951"></td>
        <td id="LC951" class="blob-line-code js-file-line">    <span class="c1">//-- low Z pT and low SpT</span></td>
      </tr>
      <tr>
        <td id="L952" class="blob-line-num js-line-number" data-line-number="952"></td>
        <td id="LC952" class="blob-line-code js-file-line">    <span class="n">PHI_LowSpT_LowPt_Zexc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_LowSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>     <span class="mi">25</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L953" class="blob-line-num js-line-number" data-line-number="953"></td>
        <td id="LC953" class="blob-line-code js-file-line">    <span class="n">genPHI_LowSpT_LowPt_Zexc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_LowSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L954" class="blob-line-num js-line-number" data-line-number="954"></td>
        <td id="LC954" class="blob-line-code js-file-line">    <span class="n">SPhi_LowSpT_LowPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_LowSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L955" class="blob-line-num js-line-number" data-line-number="955"></td>
        <td id="LC955" class="blob-line-code js-file-line">    <span class="n">genSPhi_LowSpT_LowPt_Zexc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_LowSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>       <span class="mi">50</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L956" class="blob-line-num js-line-number" data-line-number="956"></td>
        <td id="LC956" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L957" class="blob-line-num js-line-number" data-line-number="957"></td>
        <td id="LC957" class="blob-line-code js-file-line">    <span class="n">PHI_LowSpT_LowPt_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_LowSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>     <span class="mi">25</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L958" class="blob-line-num js-line-number" data-line-number="958"></td>
        <td id="LC958" class="blob-line-code js-file-line">    <span class="n">genPHI_LowSpT_LowPt_Zinc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_LowSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span> <span class="mi">25</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L959" class="blob-line-num js-line-number" data-line-number="959"></td>
        <td id="LC959" class="blob-line-code js-file-line">    <span class="n">SPhi_LowSpT_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_LowSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L960" class="blob-line-num js-line-number" data-line-number="960"></td>
        <td id="LC960" class="blob-line-code js-file-line">    <span class="n">genSPhi_LowSpT_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_LowSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>       <span class="mi">50</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L961" class="blob-line-num js-line-number" data-line-number="961"></td>
        <td id="LC961" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L962" class="blob-line-num js-line-number" data-line-number="962"></td>
        <td id="LC962" class="blob-line-code js-file-line">    <span class="c1">//-- low Z pT and high SpT</span></td>
      </tr>
      <tr>
        <td id="L963" class="blob-line-num js-line-number" data-line-number="963"></td>
        <td id="LC963" class="blob-line-code js-file-line">    <span class="n">PHI_HighSpT_LowPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_HighSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>    <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L964" class="blob-line-num js-line-number" data-line-number="964"></td>
        <td id="LC964" class="blob-line-code js-file-line">    <span class="n">genPHI_HighSpT_LowPt_Zexc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_HighSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span><span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L965" class="blob-line-num js-line-number" data-line-number="965"></td>
        <td id="LC965" class="blob-line-code js-file-line">    <span class="n">SPhi_HighSpT_LowPt_Zexc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_HighSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L966" class="blob-line-num js-line-number" data-line-number="966"></td>
        <td id="LC966" class="blob-line-code js-file-line">    <span class="n">genSPhi_HighSpT_LowPt_Zexc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_HighSpT_LowPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L967" class="blob-line-num js-line-number" data-line-number="967"></td>
        <td id="LC967" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L968" class="blob-line-num js-line-number" data-line-number="968"></td>
        <td id="LC968" class="blob-line-code js-file-line">    <span class="n">PHI_HighSpT_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_HighSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>    <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L969" class="blob-line-num js-line-number" data-line-number="969"></td>
        <td id="LC969" class="blob-line-code js-file-line">    <span class="n">genPHI_HighSpT_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_HighSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span><span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L970" class="blob-line-num js-line-number" data-line-number="970"></td>
        <td id="LC970" class="blob-line-code js-file-line">    <span class="n">SPhi_HighSpT_LowPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_HighSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L971" class="blob-line-num js-line-number" data-line-number="971"></td>
        <td id="LC971" class="blob-line-code js-file-line">    <span class="n">genSPhi_HighSpT_LowPt_Zinc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_HighSpT_LowPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L972" class="blob-line-num js-line-number" data-line-number="972"></td>
        <td id="LC972" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L973" class="blob-line-num js-line-number" data-line-number="973"></td>
        <td id="LC973" class="blob-line-code js-file-line">    <span class="c1">//-- low Z pT and low SPhi</span></td>
      </tr>
      <tr>
        <td id="L974" class="blob-line-num js-line-number" data-line-number="974"></td>
        <td id="LC974" class="blob-line-code js-file-line">    <span class="n">SpT_LowSPhi_LowPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_LowSPhi_LowPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>             <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L975" class="blob-line-num js-line-number" data-line-number="975"></td>
        <td id="LC975" class="blob-line-code js-file-line">    <span class="n">genSpT_LowSPhi_LowPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_LowSPhi_LowPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L976" class="blob-line-num js-line-number" data-line-number="976"></td>
        <td id="LC976" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L977" class="blob-line-num js-line-number" data-line-number="977"></td>
        <td id="LC977" class="blob-line-code js-file-line">    <span class="n">SpT_LowSPhi_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_LowSPhi_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>             <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L978" class="blob-line-num js-line-number" data-line-number="978"></td>
        <td id="LC978" class="blob-line-code js-file-line">    <span class="n">genSpT_LowSPhi_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_LowSPhi_LowPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L979" class="blob-line-num js-line-number" data-line-number="979"></td>
        <td id="LC979" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L980" class="blob-line-num js-line-number" data-line-number="980"></td>
        <td id="LC980" class="blob-line-code js-file-line">    <span class="c1">//-- low Z pT and high SPhi</span></td>
      </tr>
      <tr>
        <td id="L981" class="blob-line-num js-line-number" data-line-number="981"></td>
        <td id="LC981" class="blob-line-code js-file-line">    <span class="n">SpT_HighSPhi_LowPt_Zexc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_HighSPhi_LowPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L982" class="blob-line-num js-line-number" data-line-number="982"></td>
        <td id="LC982" class="blob-line-code js-file-line">    <span class="n">genSpT_HighSPhi_LowPt_Zexc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_HighSPhi_LowPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen #Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>  <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L983" class="blob-line-num js-line-number" data-line-number="983"></td>
        <td id="LC983" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L984" class="blob-line-num js-line-number" data-line-number="984"></td>
        <td id="LC984" class="blob-line-code js-file-line">    <span class="n">SpT_HighSPhi_LowPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_HighSPhi_LowPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L985" class="blob-line-num js-line-number" data-line-number="985"></td>
        <td id="LC985" class="blob-line-code js-file-line">    <span class="n">genSpT_HighSPhi_LowPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_HighSPhi_LowPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen #Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>  <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L986" class="blob-line-num js-line-number" data-line-number="986"></td>
        <td id="LC986" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L987" class="blob-line-num js-line-number" data-line-number="987"></td>
        <td id="LC987" class="blob-line-code js-file-line">    <span class="c1">//-- high Z pT</span></td>
      </tr>
      <tr>
        <td id="L988" class="blob-line-num js-line-number" data-line-number="988"></td>
        <td id="LC988" class="blob-line-code js-file-line">    <span class="n">ptBal_HighPt_Zexc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBal_HighPt_Zexc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;Vectorial pT sum: Z_{pT} + DiJet_{pT} at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>                 <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">100.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L989" class="blob-line-num js-line-number" data-line-number="989"></td>
        <td id="LC989" class="blob-line-code js-file-line">    <span class="n">genptBal_HighPt_Zexc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genptBal_HighPt_Zexc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen Vectorial pT sum: Z_{pT} + DiJet_{pT} at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>             <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">100.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L990" class="blob-line-num js-line-number" data-line-number="990"></td>
        <td id="LC990" class="blob-line-code js-file-line">    <span class="n">dPhiJets_HighPt_Zexc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJets_HighPt_Zexc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;#Delta#phi btwn jets at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                                          <span class="n">jdPhi</span><span class="p">,</span>            <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L991" class="blob-line-num js-line-number" data-line-number="991"></td>
        <td id="LC991" class="blob-line-code js-file-line">    <span class="n">gendPhiJets_HighPt_Zexc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJets_HighPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen #Delta#phi btwn jets at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                                      <span class="n">jdPhi</span><span class="p">,</span>            <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L992" class="blob-line-num js-line-number" data-line-number="992"></td>
        <td id="LC992" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_HighPt_Zexc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_HighPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;#Delta#phi btwn leptons at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                                       <span class="n">ldPhi</span><span class="p">,</span>            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L993" class="blob-line-num js-line-number" data-line-number="993"></td>
        <td id="LC993" class="blob-line-code js-file-line">    <span class="n">gendPhiLeptons_HighPt_Zexc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiLeptons_HighPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen #Delta#phi btwn leptons at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span>                               <span class="n">ldPhi</span><span class="p">,</span>            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L994" class="blob-line-num js-line-number" data-line-number="994"></td>
        <td id="LC994" class="blob-line-code js-file-line">    <span class="n">PHI_HighPt_Zexc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_HighPt_Zexc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;#phi: Angle btwn the two subsystems planes at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>                   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L995" class="blob-line-num js-line-number" data-line-number="995"></td>
        <td id="LC995" class="blob-line-code js-file-line">    <span class="n">genPHI_HighPt_Zexc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_HighPt_Zexc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>               <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L996" class="blob-line-num js-line-number" data-line-number="996"></td>
        <td id="LC996" class="blob-line-code js-file-line">    <span class="n">PHI_T_HighPt_Zexc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_T_HighPt_Zexc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;#Delta S Angle btwn lepton and jet pair in T-plane at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S&quot;</span><span class="p">,</span>                 <span class="mi">10</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L997" class="blob-line-num js-line-number" data-line-number="997"></td>
        <td id="LC997" class="blob-line-code js-file-line">    <span class="n">genPHI_T_HighPt_Zexc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_T_HighPt_Zexc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen #Delta S Angle btwn lepton and jet pair in T-plane at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S&quot;</span><span class="p">,</span>             <span class="mi">10</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L998" class="blob-line-num js-line-number" data-line-number="998"></td>
        <td id="LC998" class="blob-line-code js-file-line">    <span class="n">SpT_HighPt_Zexc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_HighPt_Zexc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                             <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L999" class="blob-line-num js-line-number" data-line-number="999"></td>
        <td id="LC999" class="blob-line-code js-file-line">    <span class="n">genSpT_HighPt_Zexc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_HighPt_Zexc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;gen #Delta_{pT}^{rel} leptons and jets combined at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1000" class="blob-line-num js-line-number" data-line-number="1000"></td>
        <td id="LC1000" class="blob-line-code js-file-line">    <span class="n">SpTJets_HighPt_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJets_HighPt_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta_{pT}^{rel} jets at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                            <span class="mi">15</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1001" class="blob-line-num js-line-number" data-line-number="1001"></td>
        <td id="LC1001" class="blob-line-code js-file-line">    <span class="n">genSpTJets_HighPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJets_HighPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta_{pT}^{rel} jets at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                        <span class="mi">15</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1002" class="blob-line-num js-line-number" data-line-number="1002"></td>
        <td id="LC1002" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_HighPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_HighPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta_{pT}^{rel} leptons at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1003" class="blob-line-num js-line-number" data-line-number="1003"></td>
        <td id="LC1003" class="blob-line-code js-file-line">    <span class="n">genSpTLeptons_HighPt_Zexc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTLeptons_HighPt_Zexc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen #Delta_{pT}^{rel} leptons at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                     <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1004" class="blob-line-num js-line-number" data-line-number="1004"></td>
        <td id="LC1004" class="blob-line-code js-file-line">    <span class="n">SPhi_HighPt_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_HighPt_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;S_{#phi}: leptons and jets combined at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1005" class="blob-line-num js-line-number" data-line-number="1005"></td>
        <td id="LC1005" class="blob-line-code js-file-line">    <span class="n">genSPhi_HighPt_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_HighPt_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen S_{#phi}: leptons and jets combined at high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>                     <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1006" class="blob-line-num js-line-number" data-line-number="1006"></td>
        <td id="LC1006" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1007" class="blob-line-num js-line-number" data-line-number="1007"></td>
        <td id="LC1007" class="blob-line-code js-file-line">    <span class="n">ptBal_HighPt_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBal_HighPt_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;Vectorial pT sum: Z_{pT} + DiJet_{pT} at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>                 <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">100.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1008" class="blob-line-num js-line-number" data-line-number="1008"></td>
        <td id="LC1008" class="blob-line-code js-file-line">    <span class="n">genptBal_HighPt_Zinc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genptBal_HighPt_Zinc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen Vectorial pT sum: Z_{pT} + DiJet_{pT} at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>             <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">100.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1009" class="blob-line-num js-line-number" data-line-number="1009"></td>
        <td id="LC1009" class="blob-line-code js-file-line">    <span class="n">dPhiJets_HighPt_Zinc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJets_HighPt_Zinc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;#Delta#phi btwn jets at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdPhi</span><span class="p">,</span>      <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1010" class="blob-line-num js-line-number" data-line-number="1010"></td>
        <td id="LC1010" class="blob-line-code js-file-line">    <span class="n">gendPhiJets_HighPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJets_HighPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen #Delta#phi btwn jets at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jdPhi</span><span class="p">,</span>      <span class="mi">15</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1011" class="blob-line-num js-line-number" data-line-number="1011"></td>
        <td id="LC1011" class="blob-line-code js-file-line">    <span class="n">dPhiLeptons_HighPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiLeptons_HighPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;#Delta#phi btwn leptons at high Z_{pT (N_{jets} #geq 2)}&quot;</span><span class="p">,</span>                                    <span class="n">ldPhi</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1012" class="blob-line-num js-line-number" data-line-number="1012"></td>
        <td id="LC1012" class="blob-line-code js-file-line">    <span class="n">gendPhiLeptons_HighPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiLeptons_HighPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;gen #Delta#phi btwn leptons at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                          <span class="n">ldPhi</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1013" class="blob-line-num js-line-number" data-line-number="1013"></td>
        <td id="LC1013" class="blob-line-code js-file-line">    <span class="n">PHI_HighPt_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_HighPt_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;#phi: Angle btwn the two subsystems planes at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>                   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1014" class="blob-line-num js-line-number" data-line-number="1014"></td>
        <td id="LC1014" class="blob-line-code js-file-line">    <span class="n">genPHI_HighPt_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_HighPt_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;gen #phi: Angle btwn the two subsystems planes at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>               <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1015" class="blob-line-num js-line-number" data-line-number="1015"></td>
        <td id="LC1015" class="blob-line-code js-file-line">    <span class="n">PHI_T_HighPt_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_T_HighPt_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;#Delta S Angle btwn lepton and jet pair in T-plane at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S&quot;</span><span class="p">,</span>                 <span class="mi">10</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1016" class="blob-line-num js-line-number" data-line-number="1016"></td>
        <td id="LC1016" class="blob-line-code js-file-line">    <span class="n">genPHI_T_HighPt_Zinc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_T_HighPt_Zinc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;gen#Delta S Angle btwn lepton and jet pair in T-plane at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S&quot;</span><span class="p">,</span>              <span class="mi">10</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1017" class="blob-line-num js-line-number" data-line-number="1017"></td>
        <td id="LC1017" class="blob-line-code js-file-line">    <span class="n">SpT_HighPt_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_HighPt_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                             <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1018" class="blob-line-num js-line-number" data-line-number="1018"></td>
        <td id="LC1018" class="blob-line-code js-file-line">    <span class="n">genSpT_HighPt_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpT_HighPt_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;gen #Delta_{pT}^{rel} leptons and jets combined at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1019" class="blob-line-num js-line-number" data-line-number="1019"></td>
        <td id="LC1019" class="blob-line-code js-file-line">    <span class="n">SpTJets_HighPt_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJets_HighPt_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta_{pT}^{rel} jets at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                            <span class="mi">15</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1020" class="blob-line-num js-line-number" data-line-number="1020"></td>
        <td id="LC1020" class="blob-line-code js-file-line">    <span class="n">genSpTJets_HighPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJets_HighPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;gen #Delta_{pT}^{rel} jets at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                        <span class="mi">15</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1021" class="blob-line-num js-line-number" data-line-number="1021"></td>
        <td id="LC1021" class="blob-line-code js-file-line">    <span class="n">SpTLeptons_HighPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTLeptons_HighPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta_{pT}^{rel} leptons at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1022" class="blob-line-num js-line-number" data-line-number="1022"></td>
        <td id="LC1022" class="blob-line-code js-file-line">    <span class="n">genSpTLeptons_HighPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTLeptons_HighPt_Zinc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gen #Delta_{pT}^{rel} leptons at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                     <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1023" class="blob-line-num js-line-number" data-line-number="1023"></td>
        <td id="LC1023" class="blob-line-code js-file-line">    <span class="n">SPhi_HighPt_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_HighPt_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;S_{#phi}: leptons and jets combined at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1024" class="blob-line-num js-line-number" data-line-number="1024"></td>
        <td id="LC1024" class="blob-line-code js-file-line">    <span class="n">genSPhi_HighPt_Zinc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSPhi_HighPt_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;gen S_{#phi}: leptons and jets combined at high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>                     <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1025" class="blob-line-num js-line-number" data-line-number="1025"></td>
        <td id="LC1025" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1026" class="blob-line-num js-line-number" data-line-number="1026"></td>
        <td id="LC1026" class="blob-line-code js-file-line">    <span class="c1">//-- high Z pT and low SpT</span></td>
      </tr>
      <tr>
        <td id="L1027" class="blob-line-num js-line-number" data-line-number="1027"></td>
        <td id="LC1027" class="blob-line-code js-file-line">    <span class="n">PHI_LowSpT_HighPt_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_LowSpT_HighPt_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Phi&quot;</span><span class="p">,</span>    <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1028" class="blob-line-num js-line-number" data-line-number="1028"></td>
        <td id="LC1028" class="blob-line-code js-file-line">    <span class="n">SPhi_LowSpT_HighPt_Zexc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_LowSpT_HighPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1029" class="blob-line-num js-line-number" data-line-number="1029"></td>
        <td id="LC1029" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1030" class="blob-line-num js-line-number" data-line-number="1030"></td>
        <td id="LC1030" class="blob-line-code js-file-line">    <span class="n">PHI_LowSpT_HighPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_LowSpT_HighPt_Zinc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Phi&quot;</span><span class="p">,</span>    <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1031" class="blob-line-num js-line-number" data-line-number="1031"></td>
        <td id="LC1031" class="blob-line-code js-file-line">    <span class="n">SPhi_LowSpT_HighPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_LowSpT_HighPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1032" class="blob-line-num js-line-number" data-line-number="1032"></td>
        <td id="LC1032" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1033" class="blob-line-num js-line-number" data-line-number="1033"></td>
        <td id="LC1033" class="blob-line-code js-file-line">    <span class="c1">//-- high Z pT and high SpT</span></td>
      </tr>
      <tr>
        <td id="L1034" class="blob-line-num js-line-number" data-line-number="1034"></td>
        <td id="LC1034" class="blob-line-code js-file-line">    <span class="n">PHI_HighSpT_HighPt_Zexc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_HighSpT_HighPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1035" class="blob-line-num js-line-number" data-line-number="1035"></td>
        <td id="LC1035" class="blob-line-code js-file-line">    <span class="n">SPhi_HighSpT_HighPt_Zexc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhiHighSpT_HighPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1036" class="blob-line-num js-line-number" data-line-number="1036"></td>
        <td id="LC1036" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1037" class="blob-line-num js-line-number" data-line-number="1037"></td>
        <td id="LC1037" class="blob-line-code js-file-line">    <span class="n">PHI_HighSpT_HighPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_HighSpT_HighPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} and high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#phi&quot;</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1038" class="blob-line-num js-line-number" data-line-number="1038"></td>
        <td id="LC1038" class="blob-line-code js-file-line">    <span class="n">SPhi_HighSpT_HighPt_Zinc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhiHighSpT_HighPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} and low Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>          <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1039" class="blob-line-num js-line-number" data-line-number="1039"></td>
        <td id="LC1039" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1040" class="blob-line-num js-line-number" data-line-number="1040"></td>
        <td id="LC1040" class="blob-line-code js-file-line">    <span class="c1">//-- high Z pT and low SPhi</span></td>
      </tr>
      <tr>
        <td id="L1041" class="blob-line-num js-line-number" data-line-number="1041"></td>
        <td id="LC1041" class="blob-line-code js-file-line">    <span class="n">SpT_LowSPhi_HighPt_Zexc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_LowSPhi_HighPt_Zexc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1042" class="blob-line-num js-line-number" data-line-number="1042"></td>
        <td id="LC1042" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1043" class="blob-line-num js-line-number" data-line-number="1043"></td>
        <td id="LC1043" class="blob-line-code js-file-line">    <span class="n">SpT_LowSPhi_HighPt_Zinc2jet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_LowSPhi_HighPt_Zinc2jet&quot;</span><span class="p">,</span>   <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} and high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1044" class="blob-line-num js-line-number" data-line-number="1044"></td>
        <td id="LC1044" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1045" class="blob-line-num js-line-number" data-line-number="1045"></td>
        <td id="LC1045" class="blob-line-code js-file-line">    <span class="c1">//-- high Z pT and high SPhi</span></td>
      </tr>
      <tr>
        <td id="L1046" class="blob-line-num js-line-number" data-line-number="1046"></td>
        <td id="LC1046" class="blob-line-code js-file-line">    <span class="n">SpT_HighSPhi_HighPt_Zexc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_HighSPhi_HighPt_Zexc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and high Z_{pT} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1047" class="blob-line-num js-line-number" data-line-number="1047"></td>
        <td id="LC1047" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1048" class="blob-line-num js-line-number" data-line-number="1048"></td>
        <td id="LC1048" class="blob-line-code js-file-line">    <span class="n">SpT_HighSPhi_HighPt_Zinc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_HighSPhi_HighPt_Zinc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} and high Z_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1049" class="blob-line-num js-line-number" data-line-number="1049"></td>
        <td id="LC1049" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1050" class="blob-line-num js-line-number" data-line-number="1050"></td>
        <td id="LC1050" class="blob-line-code js-file-line">    <span class="c1">//-- low SPhi</span></td>
      </tr>
      <tr>
        <td id="L1051" class="blob-line-num js-line-number" data-line-number="1051"></td>
        <td id="LC1051" class="blob-line-code js-file-line">    <span class="n">SpT_LowSPhi_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_LowSPhi_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1052" class="blob-line-num js-line-number" data-line-number="1052"></td>
        <td id="LC1052" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1053" class="blob-line-num js-line-number" data-line-number="1053"></td>
        <td id="LC1053" class="blob-line-code js-file-line">    <span class="n">SpT_LowSPhi_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_LowSPhi_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at low S_{#phi} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1054" class="blob-line-num js-line-number" data-line-number="1054"></td>
        <td id="LC1054" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1055" class="blob-line-num js-line-number" data-line-number="1055"></td>
        <td id="LC1055" class="blob-line-code js-file-line">    <span class="c1">//-- high SPhi</span></td>
      </tr>
      <tr>
        <td id="L1056" class="blob-line-num js-line-number" data-line-number="1056"></td>
        <td id="LC1056" class="blob-line-code js-file-line">    <span class="n">SpT_HighSPhi_Zexc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_HighSPhi_Zexc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                           <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1057" class="blob-line-num js-line-number" data-line-number="1057"></td>
        <td id="LC1057" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1058" class="blob-line-num js-line-number" data-line-number="1058"></td>
        <td id="LC1058" class="blob-line-code js-file-line">    <span class="n">SpT_HighSPhi_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpT_HighSPhi_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;#Delta_{pT}^{rel} leptons and jets combined at high S_{#phi} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                           <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1059" class="blob-line-num js-line-number" data-line-number="1059"></td>
        <td id="LC1059" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1060" class="blob-line-num js-line-number" data-line-number="1060"></td>
        <td id="LC1060" class="blob-line-code js-file-line">    <span class="c1">//-- low SpT</span></td>
      </tr>
      <tr>
        <td id="L1061" class="blob-line-num js-line-number" data-line-number="1061"></td>
        <td id="LC1061" class="blob-line-code js-file-line">    <span class="n">PHI_LowSpT_Zexc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_LowSpT_Zexc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Phi&quot;</span><span class="p">,</span>                    <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1062" class="blob-line-num js-line-number" data-line-number="1062"></td>
        <td id="LC1062" class="blob-line-code js-file-line">    <span class="n">SPhi_LowSpT_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_LowSpT_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>                          <span class="mi">50</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1063" class="blob-line-num js-line-number" data-line-number="1063"></td>
        <td id="LC1063" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1064" class="blob-line-num js-line-number" data-line-number="1064"></td>
        <td id="LC1064" class="blob-line-code js-file-line">    <span class="n">PHI_LowSpT_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_LowSpT_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;#phi: Angle btwn the two subsystems planes at low #Delta_{pT}^{rel} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Phi&quot;</span><span class="p">,</span>                    <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1065" class="blob-line-num js-line-number" data-line-number="1065"></td>
        <td id="LC1065" class="blob-line-code js-file-line">    <span class="n">SPhi_LowSpT_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_LowSpT_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;S_{#phi}: leptons and jets combined at low #Delta_{pT}^{rel} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>                          <span class="mi">50</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1066" class="blob-line-num js-line-number" data-line-number="1066"></td>
        <td id="LC1066" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1067" class="blob-line-num js-line-number" data-line-number="1067"></td>
        <td id="LC1067" class="blob-line-code js-file-line">    <span class="c1">//-- high SpT</span></td>
      </tr>
      <tr>
        <td id="L1068" class="blob-line-num js-line-number" data-line-number="1068"></td>
        <td id="LC1068" class="blob-line-code js-file-line">    <span class="n">PHI_HighSpT_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_HighSpT_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Phi&quot;</span><span class="p">,</span>                   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1069" class="blob-line-num js-line-number" data-line-number="1069"></td>
        <td id="LC1069" class="blob-line-code js-file-line">    <span class="n">SPhi_HighSpT_Zexc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_HighSpT_Zexc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1070" class="blob-line-num js-line-number" data-line-number="1070"></td>
        <td id="LC1070" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1071" class="blob-line-num js-line-number" data-line-number="1071"></td>
        <td id="LC1071" class="blob-line-code js-file-line">    <span class="n">PHI_HighSpT_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PHI_HighSpT_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;#phi: Angle btwn the two subsystems planes at high #Delta_{pT}^{rel} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Phi&quot;</span><span class="p">,</span>                   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1072" class="blob-line-num js-line-number" data-line-number="1072"></td>
        <td id="LC1072" class="blob-line-code js-file-line">    <span class="n">SPhi_HighSpT_Zinc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SPhi_HighSpT_Zinc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;S_{#phi}: leptons and jets combined at high #Delta_{pT}^{rel} (N_{jets} #geq 2)&quot;</span><span class="p">,</span><span class="s">&quot;S_{#phi}&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1073" class="blob-line-num js-line-number" data-line-number="1073"></td>
        <td id="LC1073" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1074" class="blob-line-num js-line-number" data-line-number="1074"></td>
        <td id="LC1074" class="blob-line-code js-file-line">    <span class="c1">//-- gen stuff</span></td>
      </tr>
      <tr>
        <td id="L1075" class="blob-line-num js-line-number" data-line-number="1075"></td>
        <td id="LC1075" class="blob-line-code js-file-line">    <span class="n">gendPhiJetsDeltaR_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJetsDeltaR_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta #phi btwn gen jets with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta#phi&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1076" class="blob-line-num js-line-number" data-line-number="1076"></td>
        <td id="LC1076" class="blob-line-code js-file-line">    <span class="n">resdPhiJetsDeltaR_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;resdPhiJetsDeltaR_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta #phi btwn gen jets with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta#phi&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mf">2.5</span><span class="p">,</span><span class="mf">2.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1077" class="blob-line-num js-line-number" data-line-number="1077"></td>
        <td id="LC1077" class="blob-line-code js-file-line">    <span class="n">genPHI_TDeltaR_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_TDeltaR_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta S Angle btwn gen lep and gen jet pair in T-plane with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S&quot;</span><span class="p">,</span>    <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1078" class="blob-line-num js-line-number" data-line-number="1078"></td>
        <td id="LC1078" class="blob-line-code js-file-line">    <span class="n">resPHI_TDeltaR_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;resPHI_TDeltaR_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta S Angle btwn gen lep and gen jet pair in T-plane with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S&quot;</span><span class="p">,</span>    <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mf">2.5</span><span class="p">,</span><span class="mf">2.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1079" class="blob-line-num js-line-number" data-line-number="1079"></td>
        <td id="LC1079" class="blob-line-code js-file-line">    <span class="n">genSpTJetsDeltaR_Zexc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJetsDeltaR_Zexc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;#Delta_{pT}^{rel} Gen jets with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1080" class="blob-line-num js-line-number" data-line-number="1080"></td>
        <td id="LC1080" class="blob-line-code js-file-line">    <span class="n">resSpTJetsDeltaR_Zexc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;resSpTJetsDeltaR_Zexc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;#Delta_{pT}^{rel} Gen jets with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                   <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mf">2.5</span><span class="p">,</span><span class="mf">2.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1081" class="blob-line-num js-line-number" data-line-number="1081"></td>
        <td id="LC1081" class="blob-line-code js-file-line">    <span class="n">genSpTDeltaR_Zexc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTDeltaR_Zexc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;#Delta_{pT}^{rel} with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                                   <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1082" class="blob-line-num js-line-number" data-line-number="1082"></td>
        <td id="LC1082" class="blob-line-code js-file-line">    <span class="n">resSpTDeltaR_Zexc2jet</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;resSpTDeltaR_Zexc2jet&quot;</span><span class="p">,</span>         <span class="s">&quot;#Delta_{pT}^{rel} with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span>                                                   <span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mf">2.5</span><span class="p">,</span><span class="mf">2.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1083" class="blob-line-num js-line-number" data-line-number="1083"></td>
        <td id="LC1083" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1084" class="blob-line-num js-line-number" data-line-number="1084"></td>
        <td id="LC1084" class="blob-line-code js-file-line">    <span class="n">gendPhiJetsDPS_Zexc2jet</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJetsDPS_Zexc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Delta #phi btwn gen jets matching DPS parton (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta#phi_{j_{1}j_{2}}&quot;</span><span class="p">,</span>            <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1085" class="blob-line-num js-line-number" data-line-number="1085"></td>
        <td id="LC1085" class="blob-line-code js-file-line">    <span class="n">gendPhiJetsDPSDeltaR_Zexc2jet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJetsDPSDeltaR_Zexc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;#Delta #phi btwn gen jets matching DPS parton with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta#phi&quot;</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1086" class="blob-line-num js-line-number" data-line-number="1086"></td>
        <td id="LC1086" class="blob-line-code js-file-line">    <span class="n">genPHI_TDPS_Zexc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_TDPS_Zexc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;#Delta S Angle btwn gen lepton and jet pair in T-plane (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S&quot;</span><span class="p">,</span>                         <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1087" class="blob-line-num js-line-number" data-line-number="1087"></td>
        <td id="LC1087" class="blob-line-code js-file-line">    <span class="n">genPHI_TDPSDeltaR_Zexc2jet</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genPHI_TDPSDeltaR_Zexc2jet&quot;</span><span class="p">,</span>    <span class="s">&quot;#Delta S Angle btwn gen lepton and jet pair in T-plane with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta S&quot;</span><span class="p">,</span>     <span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1088" class="blob-line-num js-line-number" data-line-number="1088"></td>
        <td id="LC1088" class="blob-line-code js-file-line">    <span class="n">genSpTJetsDPS_Zexc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJetsDPS_Zexc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;#Delta_{pT}^{rel} Gen jets matching DPS parton (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span><span class="n">nbinSpt</span><span class="p">,</span><span class="n">binSpt</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1089" class="blob-line-num js-line-number" data-line-number="1089"></td>
        <td id="LC1089" class="blob-line-code js-file-line">    <span class="n">genSpTJetsDPSDeltaR_Zexc2jet</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJetsDPSDeltaR_Zexc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;#Delta_{pT}^{rel} Gen jets matching DPS parton with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span><span class="n">nbinSpt</span><span class="p">,</span><span class="n">binSpt</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1090" class="blob-line-num js-line-number" data-line-number="1090"></td>
        <td id="LC1090" class="blob-line-code js-file-line">    <span class="n">genSpTDPS_Zexc2jet</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTDPS_Zexc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;#Delta_{pT}^{rel} with gen jets matching DPS parton (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span><span class="n">nbinSpt</span><span class="p">,</span><span class="n">binSpt</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1091" class="blob-line-num js-line-number" data-line-number="1091"></td>
        <td id="LC1091" class="blob-line-code js-file-line">    <span class="n">genSpTDPSDeltaR_Zexc2jet</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTDPSDeltaR_Zexc2jet&quot;</span><span class="p">,</span>      <span class="s">&quot;#Delta_{pT}^{rel} with gen jets matching DPS parton with #Delta R &lt; 0.5 (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span><span class="n">nbinSpt</span><span class="p">,</span><span class="n">binSpt</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1092" class="blob-line-num js-line-number" data-line-number="1092"></td>
        <td id="LC1092" class="blob-line-code js-file-line">    <span class="n">genSpTDPSPartons_Zexc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTDPSPartons_Zexc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;#Delta_{pT}^{rel} DPS partons (N_{jets} = 2)&quot;</span><span class="p">,</span><span class="s">&quot;#Delta_{pT}^{rel}&quot;</span><span class="p">,</span><span class="n">nbinSpt</span><span class="p">,</span><span class="n">binSpt</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1093" class="blob-line-num js-line-number" data-line-number="1093"></td>
        <td id="LC1093" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1094" class="blob-line-num js-line-number" data-line-number="1094"></td>
        <td id="LC1094" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZNGoodJets_Zinc&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (incl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1095" class="blob-line-num js-line-number" data-line-number="1095"></td>
        <td id="LC1095" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="s">&quot;#geq 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1096" class="blob-line-num js-line-number" data-line-number="1096"></td>
        <td id="LC1096" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span><span class="s">&quot;#geq 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1097" class="blob-line-num js-line-number" data-line-number="1097"></td>
        <td id="LC1097" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span><span class="s">&quot;#geq 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1098" class="blob-line-num js-line-number" data-line-number="1098"></td>
        <td id="LC1098" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span><span class="s">&quot;#geq 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1099" class="blob-line-num js-line-number" data-line-number="1099"></td>
        <td id="LC1099" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span><span class="s">&quot;#geq 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1100" class="blob-line-num js-line-number" data-line-number="1100"></td>
        <td id="LC1100" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span><span class="s">&quot;#geq 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1101" class="blob-line-num js-line-number" data-line-number="1101"></td>
        <td id="LC1101" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span><span class="s">&quot;#geq 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1102" class="blob-line-num js-line-number" data-line-number="1102"></td>
        <td id="LC1102" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span><span class="s">&quot;#geq 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1103" class="blob-line-num js-line-number" data-line-number="1103"></td>
        <td id="LC1103" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span><span class="s">&quot;#geq 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1104" class="blob-line-num js-line-number" data-line-number="1104"></td>
        <td id="LC1104" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;#geq 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1105" class="blob-line-num js-line-number" data-line-number="1105"></td>
        <td id="LC1105" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zinc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;#geq 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1106" class="blob-line-num js-line-number" data-line-number="1106"></td>
        <td id="LC1106" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1107" class="blob-line-num js-line-number" data-line-number="1107"></td>
        <td id="LC1107" class="blob-line-code js-file-line">    <span class="k">if</span> <span class="p">(</span> <span class="n">doWJets</span> <span class="p">)</span>  <span class="n">genZNGoodJets_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZNGoodJets_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1108" class="blob-line-num js-line-number" data-line-number="1108"></td>
        <td id="LC1108" class="blob-line-code js-file-line">    <span class="k">else</span> <span class="n">genZNGoodJets_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZNGoodJets_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">8</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">7.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1109" class="blob-line-num js-line-number" data-line-number="1109"></td>
        <td id="LC1109" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1110" class="blob-line-num js-line-number" data-line-number="1110"></td>
        <td id="LC1110" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span><span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1111" class="blob-line-num js-line-number" data-line-number="1111"></td>
        <td id="LC1111" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span><span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1112" class="blob-line-num js-line-number" data-line-number="1112"></td>
        <td id="LC1112" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span><span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1113" class="blob-line-num js-line-number" data-line-number="1113"></td>
        <td id="LC1113" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span><span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1114" class="blob-line-num js-line-number" data-line-number="1114"></td>
        <td id="LC1114" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span><span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1115" class="blob-line-num js-line-number" data-line-number="1115"></td>
        <td id="LC1115" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span><span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1116" class="blob-line-num js-line-number" data-line-number="1116"></td>
        <td id="LC1116" class="blob-line-code js-file-line">    <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span><span class="s">&quot;= 7&quot;</span><span class="p">);</span> </td>
      </tr>
      <tr>
        <td id="L1117" class="blob-line-num js-line-number" data-line-number="1117"></td>
        <td id="LC1117" class="blob-line-code js-file-line">    <span class="k">if</span> <span class="p">(</span> <span class="n">doWJets</span> <span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L1118" class="blob-line-num js-line-number" data-line-number="1118"></td>
        <td id="LC1118" class="blob-line-code js-file-line">        <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span><span class="s">&quot;#geq 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1119" class="blob-line-num js-line-number" data-line-number="1119"></td>
        <td id="LC1119" class="blob-line-code js-file-line">        <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;#geq 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1120" class="blob-line-num js-line-number" data-line-number="1120"></td>
        <td id="LC1120" class="blob-line-code js-file-line">        <span class="n">genZNGoodJets_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;#geq 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1121" class="blob-line-num js-line-number" data-line-number="1121"></td>
        <td id="LC1121" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L1122" class="blob-line-num js-line-number" data-line-number="1122"></td>
        <td id="LC1122" class="blob-line-code js-file-line">    <span class="c1">//Correlations</span></td>
      </tr>
      <tr>
        <td id="L1123" class="blob-line-num js-line-number" data-line-number="1123"></td>
        <td id="LC1123" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1124" class="blob-line-num js-line-number" data-line-number="1124"></td>
        <td id="LC1124" class="blob-line-code js-file-line">    <span class="n">gendPhiJetsDPSDeltaR_ZpT_Zexc2jet</span> <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;gendPhiJetsDPSDeltaR_ZpT_Zexc2jet&quot;</span><span class="p">,</span> <span class="s">&quot;gendPhiJetsDPSDeltaR_ZpT_Zexc2jet&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">,</span> <span class="mi">100</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">100</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1125" class="blob-line-num js-line-number" data-line-number="1125"></td>
        <td id="LC1125" class="blob-line-code js-file-line">    <span class="n">partonX2D</span>                          <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;partonX2D&quot;</span><span class="p">,</span><span class="s">&quot;parton X: x1 vs x2&quot;</span><span class="p">,</span><span class="mi">100</span><span class="p">,</span><span class="mf">0.0001</span><span class="p">,</span><span class="mf">0.2</span><span class="p">,</span><span class="mi">100</span><span class="p">,</span><span class="mf">0.0001</span><span class="p">,</span><span class="mf">0.2</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1126" class="blob-line-num js-line-number" data-line-number="1126"></td>
        <td id="LC1126" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1127" class="blob-line-num js-line-number" data-line-number="1127"></td>
        <td id="LC1127" class="blob-line-code js-file-line">    <span class="n">gendeltaRjetMu</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendeltaRjetMu&quot;</span><span class="p">,</span> <span class="s">&quot;gen delta R btwn jet and muon&quot;</span><span class="p">,</span> <span class="s">&quot;#R&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1128" class="blob-line-num js-line-number" data-line-number="1128"></td>
        <td id="LC1128" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1129" class="blob-line-num js-line-number" data-line-number="1129"></td>
        <td id="LC1129" class="blob-line-code js-file-line">    <span class="c1">/// additional information</span></td>
      </tr>
      <tr>
        <td id="L1130" class="blob-line-num js-line-number" data-line-number="1130"></td>
        <td id="LC1130" class="blob-line-code js-file-line">    <span class="c1">// Muoisolation</span></td>
      </tr>
      <tr>
        <td id="L1131" class="blob-line-num js-line-number" data-line-number="1131"></td>
        <td id="LC1131" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1132" class="blob-line-num js-line-number" data-line-number="1132"></td>
        <td id="LC1132" class="blob-line-code js-file-line">    <span class="n">MuDetIsoRhoCorr</span>                    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MuDetIsoRhoCorr&quot;</span><span class="p">,</span>  <span class="s">&quot;Muon Detect. Iso #rho corr.&quot;</span><span class="p">,</span> <span class="s">&quot;l_{Iso}^{Det.}&quot;</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">1.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1133" class="blob-line-num js-line-number" data-line-number="1133"></td>
        <td id="LC1133" class="blob-line-code js-file-line">    <span class="n">MuPFIsoDBetaCorr</span>                   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MuPFIsoDBetaCorr&quot;</span><span class="p">,</span> <span class="s">&quot;Muon PF Iso DBeta corr.&quot;</span><span class="p">,</span>     <span class="s">&quot;l_{Iso}^{PF}&quot;</span><span class="p">,</span>   <span class="mi">30</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">1.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1134" class="blob-line-num js-line-number" data-line-number="1134"></td>
        <td id="LC1134" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1135" class="blob-line-num js-line-number" data-line-number="1135"></td>
        <td id="LC1135" class="blob-line-code js-file-line">    <span class="n">deltaRjetMu</span>                        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;deltaRjetMu&quot;</span><span class="p">,</span> <span class="s">&quot;delta R btwn jet and muon&quot;</span><span class="p">,</span> <span class="s">&quot;#R&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mf">2.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1136" class="blob-line-num js-line-number" data-line-number="1136"></td>
        <td id="LC1136" class="blob-line-code js-file-line">    <span class="n">deltaPtjetMu</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;deltaPtjetMu&quot;</span><span class="p">,</span> <span class="s">&quot;delta Pt btwn jet and muon if dR&lt;0.5&quot;</span><span class="p">,</span> <span class="s">&quot;#R&quot;</span><span class="p">,</span> <span class="mi">150</span><span class="p">,</span> <span class="o">-</span><span class="mf">75.</span><span class="p">,</span> <span class="mf">75.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1137" class="blob-line-num js-line-number" data-line-number="1137"></td>
        <td id="LC1137" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1138" class="blob-line-num js-line-number" data-line-number="1138"></td>
        <td id="LC1138" class="blob-line-code js-file-line">    <span class="c1">//TH2D* jecVspt=newTH1D(&quot;jecVspt&quot;,&quot;jec Vs pt&quot;,&quot;jec&quot;,&quot;pt&quot;,80,0.,400,100,0,0.5);</span></td>
      </tr>
      <tr>
        <td id="L1139" class="blob-line-num js-line-number" data-line-number="1139"></td>
        <td id="LC1139" class="blob-line-code js-file-line">    <span class="n">NVtx</span>                          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;NVtx&quot;</span><span class="p">,</span><span class="s">&quot;Number of vertices&quot;</span><span class="p">,</span><span class="s">&quot;#Vtx&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1140" class="blob-line-num js-line-number" data-line-number="1140"></td>
        <td id="LC1140" class="blob-line-code js-file-line">    <span class="n">TruePU_0</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TruePU_0&quot;</span><span class="p">,</span><span class="s">&quot;True pile-up 0 jet&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1141" class="blob-line-num js-line-number" data-line-number="1141"></td>
        <td id="LC1141" class="blob-line-code js-file-line">    <span class="n">TruePU_1</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TruePU_1&quot;</span><span class="p">,</span><span class="s">&quot;True pile-up 1 jet&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1142" class="blob-line-num js-line-number" data-line-number="1142"></td>
        <td id="LC1142" class="blob-line-code js-file-line">    <span class="n">TruePU_2</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TruePU_2&quot;</span><span class="p">,</span><span class="s">&quot;True pile-up 2 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1143" class="blob-line-num js-line-number" data-line-number="1143"></td>
        <td id="LC1143" class="blob-line-code js-file-line">    <span class="n">TruePU_3</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TruePU_3&quot;</span><span class="p">,</span><span class="s">&quot;True pile-up 3 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1144" class="blob-line-num js-line-number" data-line-number="1144"></td>
        <td id="LC1144" class="blob-line-code js-file-line">    <span class="n">TruePU_4</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TruePU_4&quot;</span><span class="p">,</span><span class="s">&quot;True pile-up 4 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1145" class="blob-line-num js-line-number" data-line-number="1145"></td>
        <td id="LC1145" class="blob-line-code js-file-line">    <span class="n">TruePU_5</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TruePU_5&quot;</span><span class="p">,</span><span class="s">&quot;True pile-up 5 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1146" class="blob-line-num js-line-number" data-line-number="1146"></td>
        <td id="LC1146" class="blob-line-code js-file-line">    <span class="n">TruePU_6</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TruePU_6&quot;</span><span class="p">,</span><span class="s">&quot;True pile-up 6 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1147" class="blob-line-num js-line-number" data-line-number="1147"></td>
        <td id="LC1147" class="blob-line-code js-file-line">    <span class="n">TruePU_7</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TruePU_7&quot;</span><span class="p">,</span><span class="s">&quot;True pile-up 7 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1148" class="blob-line-num js-line-number" data-line-number="1148"></td>
        <td id="LC1148" class="blob-line-code js-file-line">    <span class="n">PU_0</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PU_0&quot;</span><span class="p">,</span><span class="s">&quot;pile-up 0 jet&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1149" class="blob-line-num js-line-number" data-line-number="1149"></td>
        <td id="LC1149" class="blob-line-code js-file-line">    <span class="n">PU_1</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PU_1&quot;</span><span class="p">,</span><span class="s">&quot;pile-up 1 jet&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1150" class="blob-line-num js-line-number" data-line-number="1150"></td>
        <td id="LC1150" class="blob-line-code js-file-line">    <span class="n">PU_2</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PU_2&quot;</span><span class="p">,</span><span class="s">&quot;pile-up 2 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1151" class="blob-line-num js-line-number" data-line-number="1151"></td>
        <td id="LC1151" class="blob-line-code js-file-line">    <span class="n">PU_3</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PU_3&quot;</span><span class="p">,</span><span class="s">&quot;pile-up 3 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1152" class="blob-line-num js-line-number" data-line-number="1152"></td>
        <td id="LC1152" class="blob-line-code js-file-line">    <span class="n">PU_4</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PU_4&quot;</span><span class="p">,</span><span class="s">&quot;pile-up 4 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1153" class="blob-line-num js-line-number" data-line-number="1153"></td>
        <td id="LC1153" class="blob-line-code js-file-line">    <span class="n">PU_5</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PU_5&quot;</span><span class="p">,</span><span class="s">&quot;pile-up 5 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1154" class="blob-line-num js-line-number" data-line-number="1154"></td>
        <td id="LC1154" class="blob-line-code js-file-line">    <span class="n">PU_6</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PU_6&quot;</span><span class="p">,</span><span class="s">&quot;pile-up 6 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1155" class="blob-line-num js-line-number" data-line-number="1155"></td>
        <td id="LC1155" class="blob-line-code js-file-line">    <span class="n">PU_7</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PU_7&quot;</span><span class="p">,</span><span class="s">&quot;pile-up 7 jets&quot;</span><span class="p">,</span><span class="s">&quot;#pu&quot;</span><span class="p">,</span><span class="mi">45</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">45.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1156" class="blob-line-num js-line-number" data-line-number="1156"></td>
        <td id="LC1156" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span> <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;ZNGoodJetsBeta_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Beta cut vs Jet Counter (excl.) &quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">,</span> <span class="mi">10</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">9.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1157" class="blob-line-num js-line-number" data-line-number="1157"></td>
        <td id="LC1157" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1158" class="blob-line-num js-line-number" data-line-number="1158"></td>
        <td id="LC1158" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1159" class="blob-line-num js-line-number" data-line-number="1159"></td>
        <td id="LC1159" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1160" class="blob-line-num js-line-number" data-line-number="1160"></td>
        <td id="LC1160" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1161" class="blob-line-num js-line-number" data-line-number="1161"></td>
        <td id="LC1161" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1162" class="blob-line-num js-line-number" data-line-number="1162"></td>
        <td id="LC1162" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1163" class="blob-line-num js-line-number" data-line-number="1163"></td>
        <td id="LC1163" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1164" class="blob-line-num js-line-number" data-line-number="1164"></td>
        <td id="LC1164" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1165" class="blob-line-num js-line-number" data-line-number="1165"></td>
        <td id="LC1165" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;= 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1166" class="blob-line-num js-line-number" data-line-number="1166"></td>
        <td id="LC1166" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;= 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1167" class="blob-line-num js-line-number" data-line-number="1167"></td>
        <td id="LC1167" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsBeta_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;= 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1168" class="blob-line-num js-line-number" data-line-number="1168"></td>
        <td id="LC1168" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1169" class="blob-line-num js-line-number" data-line-number="1169"></td>
        <td id="LC1169" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1170" class="blob-line-num js-line-number" data-line-number="1170"></td>
        <td id="LC1170" class="blob-line-code js-file-line">    <span class="n">Beta</span>                          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;Beta&quot;</span><span class="p">,</span><span class="s">&quot;Jet PU variable Beta&quot;</span><span class="p">,</span><span class="s">&quot;Beta&quot;</span><span class="p">,</span><span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1171" class="blob-line-num js-line-number" data-line-number="1171"></td>
        <td id="LC1171" class="blob-line-code js-file-line">    <span class="n">BetaStar</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;BetaStar&quot;</span><span class="p">,</span><span class="s">&quot;Jet PU variable BetaStar&quot;</span><span class="p">,</span><span class="s">&quot;BetaStar&quot;</span><span class="p">,</span><span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1172" class="blob-line-num js-line-number" data-line-number="1172"></td>
        <td id="LC1172" class="blob-line-code js-file-line">    <span class="n">puBeta_JetsMatchGenJets</span>       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;puBeta_JetsMatchGenJets&quot;</span><span class="p">,</span> <span class="s">&quot;puBeta_JetsMatchGenJets&quot;</span><span class="p">,</span> <span class="s">&quot;Beta&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1173" class="blob-line-num js-line-number" data-line-number="1173"></td>
        <td id="LC1173" class="blob-line-code js-file-line">    <span class="n">puBetaStar_JetsMatchGenJets</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;puBetaStar_JetsMatchGenJets&quot;</span><span class="p">,</span> <span class="s">&quot;puBetaStar_JetsMatchGenJets&quot;</span><span class="p">,</span> <span class="s">&quot;Beta&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1174" class="blob-line-num js-line-number" data-line-number="1174"></td>
        <td id="LC1174" class="blob-line-code js-file-line">    <span class="n">puBeta_JetsNoMatchGenJets</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;puBeta_JetsNoMatchGenJets&quot;</span><span class="p">,</span> <span class="s">&quot;puBeta_JetsNoMatchGenJets&quot;</span><span class="p">,</span> <span class="s">&quot;Beta&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1175" class="blob-line-num js-line-number" data-line-number="1175"></td>
        <td id="LC1175" class="blob-line-code js-file-line">    <span class="n">puBetaStar_JetsNoMatchGenJets</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;puBetaStar_JetsNoMatchGenJets&quot;</span><span class="p">,</span> <span class="s">&quot;puBetaStar_JetsNoMatchGenJets&quot;</span><span class="p">,</span> <span class="s">&quot;Beta&quot;</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1176" class="blob-line-num js-line-number" data-line-number="1176"></td>
        <td id="LC1176" class="blob-line-code js-file-line">    <span class="n">puMVA</span>                         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;puMVA&quot;</span><span class="p">,</span><span class="s">&quot;Jet PU variable from MVA&quot;</span><span class="p">,</span><span class="s">&quot;puMVA&quot;</span><span class="p">,</span><span class="mi">40</span><span class="p">,</span><span class="o">-</span><span class="mf">1.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1177" class="blob-line-num js-line-number" data-line-number="1177"></td>
        <td id="LC1177" class="blob-line-code js-file-line">    <span class="n">puMVA_JetsMatchGenJets</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;puMVA_JetsMatchGenJets&quot;</span><span class="p">,</span><span class="s">&quot;Jet PU variable from MVA for matching jets&quot;</span><span class="p">,</span><span class="s">&quot;puMVA&quot;</span><span class="p">,</span><span class="mi">40</span><span class="p">,</span><span class="o">-</span><span class="mf">1.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1178" class="blob-line-num js-line-number" data-line-number="1178"></td>
        <td id="LC1178" class="blob-line-code js-file-line">    <span class="n">puMVA_JetsNoMatchGenJets</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;puMVA_JetsNoMatchGenJets&quot;</span><span class="p">,</span><span class="s">&quot;Jet PU variable from MVA for non matching jets&quot;</span><span class="p">,</span><span class="s">&quot;puMVA&quot;</span><span class="p">,</span><span class="mi">40</span><span class="p">,</span><span class="o">-</span><span class="mf">1.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1179" class="blob-line-num js-line-number" data-line-number="1179"></td>
        <td id="LC1179" class="blob-line-code js-file-line">    <span class="n">jetsEta_JetsMatchGenJets</span>      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;jetsEta_JetsMatchGenJets&quot;</span><span class="p">,</span><span class="s">&quot;Jet Eta for matching jets&quot;</span><span class="p">,</span><span class="s">&quot;puMVA&quot;</span><span class="p">,</span><span class="mi">48</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span><span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1180" class="blob-line-num js-line-number" data-line-number="1180"></td>
        <td id="LC1180" class="blob-line-code js-file-line">    <span class="n">jetsEta_JetsNoMatchGenJets</span>    <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;jetsEta_JetsNoMatchGenJets&quot;</span><span class="p">,</span><span class="s">&quot;Jet Eta for non matching jets&quot;</span><span class="p">,</span><span class="s">&quot;puMVA&quot;</span><span class="p">,</span><span class="mi">48</span><span class="p">,</span><span class="o">-</span><span class="mf">2.4</span><span class="p">,</span><span class="mf">2.4</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1181" class="blob-line-num js-line-number" data-line-number="1181"></td>
        <td id="LC1181" class="blob-line-code js-file-line">    <span class="n">FirstJetdEtaGenReco_Zinc1</span>	<span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetdEtaGenReco_Zinc1&quot;</span><span class="p">,</span><span class="s">&quot;#delta#eta(gen,reco) for 1st leading jet&quot;</span><span class="p">,</span><span class="s">&quot;#delta#eta&quot;</span><span class="p">,</span><span class="mi">300</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">7.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1182" class="blob-line-num js-line-number" data-line-number="1182"></td>
        <td id="LC1182" class="blob-line-code js-file-line">    <span class="n">FourthJetdEtaGenReco_Zinc4</span>	<span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FourthJetdEtaGenReco_Zinc4&quot;</span><span class="p">,</span><span class="s">&quot;#delta#eta(gen,reco) for 4th leading jet&quot;</span><span class="p">,</span><span class="s">&quot;#delta#eta&quot;</span><span class="p">,</span><span class="mi">300</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">7.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1183" class="blob-line-num js-line-number" data-line-number="1183"></td>
        <td id="LC1183" class="blob-line-code js-file-line">    <span class="n">puMVAvsBeta</span>                   <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;puMVA vs beta&quot;</span><span class="p">,</span><span class="s">&quot;Jet PU variable from MVA vs Beta&quot;</span><span class="p">,</span><span class="mi">50</span><span class="p">,</span><span class="o">-</span><span class="mf">1.</span><span class="p">,</span><span class="mf">1.</span><span class="p">,</span><span class="mi">50</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">1.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1184" class="blob-line-num js-line-number" data-line-number="1184"></td>
        <td id="LC1184" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1185" class="blob-line-num js-line-number" data-line-number="1185"></td>
        <td id="LC1185" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1186" class="blob-line-num js-line-number" data-line-number="1186"></td>
        <td id="LC1186" class="blob-line-code js-file-line">    <span class="n">PUWeight</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PUWeight&quot;</span><span class="p">,</span><span class="s">&quot;PU weight Z all&quot;</span><span class="p">,</span><span class="s">&quot;PU weight Z all&quot;</span><span class="p">,</span><span class="mi">500</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">14.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1187" class="blob-line-num js-line-number" data-line-number="1187"></td>
        <td id="LC1187" class="blob-line-code js-file-line">    <span class="n">PUWeight0</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PUWeight0&quot;</span><span class="p">,</span><span class="s">&quot;PU weight Z+0jet&quot;</span><span class="p">,</span><span class="s">&quot;PU weight Z+0jet&quot;</span><span class="p">,</span><span class="mi">500</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">14.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1188" class="blob-line-num js-line-number" data-line-number="1188"></td>
        <td id="LC1188" class="blob-line-code js-file-line">    <span class="n">PUWeight1</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;PUWeigh1&quot;</span><span class="p">,</span><span class="s">&quot;PU weight Z+jet&gt;0 &quot;</span><span class="p">,</span><span class="s">&quot;PU weight Z+jet&gt;0&quot;</span><span class="p">,</span><span class="mi">500</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">14.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1189" class="blob-line-num js-line-number" data-line-number="1189"></td>
        <td id="LC1189" class="blob-line-code js-file-line">    <span class="n">MuPlusPt</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MuPlusPt&quot;</span><span class="p">,</span><span class="s">&quot;Pt of positive muon&quot;</span><span class="p">,</span><span class="s">&quot;pT [GeV]&quot;</span><span class="p">,</span><span class="mi">150</span><span class="p">,</span><span class="mf">10.</span><span class="p">,</span><span class="mf">160.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1190" class="blob-line-num js-line-number" data-line-number="1190"></td>
        <td id="LC1190" class="blob-line-code js-file-line">    <span class="n">MuMinusPt</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MuMinusPt&quot;</span><span class="p">,</span><span class="s">&quot;Pt of negative muon&quot;</span><span class="p">,</span><span class="s">&quot;pT [GeV]&quot;</span><span class="p">,</span><span class="mi">150</span><span class="p">,</span><span class="mf">10.</span><span class="p">,</span><span class="mf">160.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1191" class="blob-line-num js-line-number" data-line-number="1191"></td>
        <td id="LC1191" class="blob-line-code js-file-line">    <span class="n">MuPlusEta</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MuPlusEta&quot;</span><span class="p">,</span><span class="s">&quot;#eta of positive muon&quot;</span><span class="p">,</span><span class="s">&quot;#eta&quot;</span><span class="p">,</span><span class="mi">250</span><span class="p">,</span><span class="o">-</span><span class="mf">2.5</span><span class="p">,</span><span class="mf">2.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1192" class="blob-line-num js-line-number" data-line-number="1192"></td>
        <td id="LC1192" class="blob-line-code js-file-line">    <span class="n">MuMinusEta</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MuMinusEta&quot;</span><span class="p">,</span><span class="s">&quot;#eta of negative muon&quot;</span><span class="p">,</span><span class="s">&quot;#eta&quot;</span><span class="p">,</span><span class="mi">250</span><span class="p">,</span><span class="o">-</span><span class="mf">2.5</span><span class="p">,</span><span class="mf">2.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1193" class="blob-line-num js-line-number" data-line-number="1193"></td>
        <td id="LC1193" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1194" class="blob-line-num js-line-number" data-line-number="1194"></td>
        <td id="LC1194" class="blob-line-code js-file-line">    <span class="c1">/// additional MET histograms</span></td>
      </tr>
      <tr>
        <td id="L1195" class="blob-line-num js-line-number" data-line-number="1195"></td>
        <td id="LC1195" class="blob-line-code js-file-line">    <span class="n">fullMET</span>                       <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MET&quot;</span><span class="p">,</span><span class="s">&quot;MET for all passing leptons&quot;</span><span class="p">,</span><span class="s">&quot;MET for all passing leptons&quot;</span><span class="p">,</span><span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">400.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1196" class="blob-line-num js-line-number" data-line-number="1196"></td>
        <td id="LC1196" class="blob-line-code js-file-line">    <span class="n">fullMET_pfMETPFlow</span>            <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;fullMET_pfMETPFlow&quot;</span><span class="p">,</span><span class="s">&quot;fullMET_pfMETPFlow            for all passing leptons&quot;</span><span class="p">,</span><span class="s">&quot;MET for all passing leptons&quot;</span><span class="p">,</span><span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">400.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1197" class="blob-line-num js-line-number" data-line-number="1197"></td>
        <td id="LC1197" class="blob-line-code js-file-line">    <span class="n">fullMET_pfMet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;fullMET_pfMet&quot;</span><span class="p">,</span><span class="s">&quot;fullMET_pfMet                 for all passing leptons&quot;</span><span class="p">,</span><span class="s">&quot;MET for all passing leptons&quot;</span><span class="p">,</span><span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">400.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1198" class="blob-line-num js-line-number" data-line-number="1198"></td>
        <td id="LC1198" class="blob-line-code js-file-line">    <span class="n">fullMET_pfType1CorrectedMet</span>   <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;fullMET_pfType1CorrectedMet&quot;</span><span class="p">,</span><span class="s">&quot;fullMET_pfType1CorrectedMet   for all passing leptons&quot;</span><span class="p">,</span><span class="s">&quot;MET for all passing leptons&quot;</span><span class="p">,</span><span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">400.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1199" class="blob-line-num js-line-number" data-line-number="1199"></td>
        <td id="LC1199" class="blob-line-code js-file-line">    <span class="n">fullMET_pfType1p2CorrectedMet</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;fullMET_pfType1p2CorrectedMet&quot;</span><span class="p">,</span><span class="s">&quot;fullMET_pfType1p2CorrectedMet for all passing leptons&quot;</span><span class="p">,</span><span class="s">&quot;MET for all passing leptons&quot;</span><span class="p">,</span><span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">400.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1200" class="blob-line-num js-line-number" data-line-number="1200"></td>
        <td id="LC1200" class="blob-line-code js-file-line">    <span class="n">fullMT</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MT&quot;</span> <span class="p">,</span><span class="s">&quot;MT for all passing leptons&quot;</span> <span class="p">,</span><span class="s">&quot;MT for all passing leptons&quot;</span><span class="p">,</span><span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">400.</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1201" class="blob-line-num js-line-number" data-line-number="1201"></td>
        <td id="LC1201" class="blob-line-code js-file-line">    <span class="n">METvslepIso</span>     <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;MET vs lep Iso&quot;</span> <span class="p">,</span><span class="s">&quot;MET vs leptons Iso for all passing lepton&quot;</span><span class="p">,</span><span class="mi">100</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">300.</span><span class="p">,</span><span class="mi">100</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mi">1</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1202" class="blob-line-num js-line-number" data-line-number="1202"></td>
        <td id="LC1202" class="blob-line-code js-file-line">    <span class="n">MTvslepIso</span>      <span class="o">=</span> <span class="n">newTH2D</span><span class="p">(</span><span class="s">&quot;MT vs lep Iso&quot;</span> <span class="p">,</span><span class="s">&quot;MT vs leptons Iso for all passing lepton&quot;</span><span class="p">,</span><span class="mi">100</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mf">300.</span><span class="p">,</span><span class="mi">100</span><span class="p">,</span> <span class="mf">0.</span><span class="p">,</span> <span class="mi">1</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1203" class="blob-line-num js-line-number" data-line-number="1203"></td>
        <td id="LC1203" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1204" class="blob-line-num js-line-number" data-line-number="1204"></td>
        <td id="LC1204" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1205" class="blob-line-num js-line-number" data-line-number="1205"></td>
        <td id="LC1205" class="blob-line-code js-file-line">    <span class="n">MET_Zinc0jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MET_Zinc0jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET (N_{jets} #geq 0)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1206" class="blob-line-num js-line-number" data-line-number="1206"></td>
        <td id="LC1206" class="blob-line-code js-file-line">    <span class="n">MET_Zinc1jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MET_Zinc1jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET (N_{jets} #geq 1)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1207" class="blob-line-num js-line-number" data-line-number="1207"></td>
        <td id="LC1207" class="blob-line-code js-file-line">    <span class="n">MET_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MET_Zinc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET (N_{jets} #geq 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1208" class="blob-line-num js-line-number" data-line-number="1208"></td>
        <td id="LC1208" class="blob-line-code js-file-line">    <span class="n">MET_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MET_Zinc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET (N_{jets} #geq 3)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1209" class="blob-line-num js-line-number" data-line-number="1209"></td>
        <td id="LC1209" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1210" class="blob-line-num js-line-number" data-line-number="1210"></td>
        <td id="LC1210" class="blob-line-code js-file-line">    <span class="n">METphi_Zinc0jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphi_Zinc0jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET #phi (N_{jets} #geq 0)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1211" class="blob-line-num js-line-number" data-line-number="1211"></td>
        <td id="LC1211" class="blob-line-code js-file-line">    <span class="n">METphi_Zinc1jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphi_Zinc1jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET #phi (N_{jets} #geq 1)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1212" class="blob-line-num js-line-number" data-line-number="1212"></td>
        <td id="LC1212" class="blob-line-code js-file-line">    <span class="n">METphi_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphi_Zinc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1213" class="blob-line-num js-line-number" data-line-number="1213"></td>
        <td id="LC1213" class="blob-line-code js-file-line">    <span class="n">METphi_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphi_Zinc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET #phi (N_{jets} #geq 3)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1214" class="blob-line-num js-line-number" data-line-number="1214"></td>
        <td id="LC1214" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1215" class="blob-line-num js-line-number" data-line-number="1215"></td>
        <td id="LC1215" class="blob-line-code js-file-line">    <span class="n">MT_Zinc0jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MT_Zinc0jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MT (N_{jets} #geq 0)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1216" class="blob-line-num js-line-number" data-line-number="1216"></td>
        <td id="LC1216" class="blob-line-code js-file-line">    <span class="n">MT_Zinc1jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MT_Zinc1jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MT (N_{jets} #geq 1)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1217" class="blob-line-num js-line-number" data-line-number="1217"></td>
        <td id="LC1217" class="blob-line-code js-file-line">    <span class="n">MT_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MT_Zinc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MT (N_{jets} #geq 2)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1218" class="blob-line-num js-line-number" data-line-number="1218"></td>
        <td id="LC1218" class="blob-line-code js-file-line">    <span class="n">MT_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MT_Zinc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MT (N_{jets} #geq 3)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1219" class="blob-line-num js-line-number" data-line-number="1219"></td>
        <td id="LC1219" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1220" class="blob-line-num js-line-number" data-line-number="1220"></td>
        <td id="LC1220" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1221" class="blob-line-num js-line-number" data-line-number="1221"></td>
        <td id="LC1221" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1222" class="blob-line-num js-line-number" data-line-number="1222"></td>
        <td id="LC1222" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJetsEWK_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1223" class="blob-line-num js-line-number" data-line-number="1223"></td>
        <td id="LC1223" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1224" class="blob-line-num js-line-number" data-line-number="1224"></td>
        <td id="LC1224" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1225" class="blob-line-num js-line-number" data-line-number="1225"></td>
        <td id="LC1225" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1226" class="blob-line-num js-line-number" data-line-number="1226"></td>
        <td id="LC1226" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1227" class="blob-line-num js-line-number" data-line-number="1227"></td>
        <td id="LC1227" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1228" class="blob-line-num js-line-number" data-line-number="1228"></td>
        <td id="LC1228" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1229" class="blob-line-num js-line-number" data-line-number="1229"></td>
        <td id="LC1229" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1230" class="blob-line-num js-line-number" data-line-number="1230"></td>
        <td id="LC1230" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1231" class="blob-line-num js-line-number" data-line-number="1231"></td>
        <td id="LC1231" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;= 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1232" class="blob-line-num js-line-number" data-line-number="1232"></td>
        <td id="LC1232" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;= 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1233" class="blob-line-num js-line-number" data-line-number="1233"></td>
        <td id="LC1233" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;= 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1234" class="blob-line-num js-line-number" data-line-number="1234"></td>
        <td id="LC1234" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJetsEWKbtw_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Between: Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1235" class="blob-line-num js-line-number" data-line-number="1235"></td>
        <td id="LC1235" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1236" class="blob-line-num js-line-number" data-line-number="1236"></td>
        <td id="LC1236" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1237" class="blob-line-num js-line-number" data-line-number="1237"></td>
        <td id="LC1237" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1238" class="blob-line-num js-line-number" data-line-number="1238"></td>
        <td id="LC1238" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1239" class="blob-line-num js-line-number" data-line-number="1239"></td>
        <td id="LC1239" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1240" class="blob-line-num js-line-number" data-line-number="1240"></td>
        <td id="LC1240" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1241" class="blob-line-num js-line-number" data-line-number="1241"></td>
        <td id="LC1241" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1242" class="blob-line-num js-line-number" data-line-number="1242"></td>
        <td id="LC1242" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1243" class="blob-line-num js-line-number" data-line-number="1243"></td>
        <td id="LC1243" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;= 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1244" class="blob-line-num js-line-number" data-line-number="1244"></td>
        <td id="LC1244" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;= 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1245" class="blob-line-num js-line-number" data-line-number="1245"></td>
        <td id="LC1245" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;= 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1246" class="blob-line-num js-line-number" data-line-number="1246"></td>
        <td id="LC1246" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1247" class="blob-line-num js-line-number" data-line-number="1247"></td>
        <td id="LC1247" class="blob-line-code js-file-line">    <span class="c1">// MET properties</span></td>
      </tr>
      <tr>
        <td id="L1248" class="blob-line-num js-line-number" data-line-number="1248"></td>
        <td id="LC1248" class="blob-line-code js-file-line">    <span class="n">METEWK_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METEWK_Zinc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET (N_{jets} #geq 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">500</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1249" class="blob-line-num js-line-number" data-line-number="1249"></td>
        <td id="LC1249" class="blob-line-code js-file-line">    <span class="n">METEWK_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METEWK_Zinc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET (N_{jets} #geq 3)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">500</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1250" class="blob-line-num js-line-number" data-line-number="1250"></td>
        <td id="LC1250" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1251" class="blob-line-num js-line-number" data-line-number="1251"></td>
        <td id="LC1251" class="blob-line-code js-file-line">    <span class="n">METphiEWK_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphiEWK_Zinc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1252" class="blob-line-num js-line-number" data-line-number="1252"></td>
        <td id="LC1252" class="blob-line-code js-file-line">    <span class="n">METphiEWK_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphiEWK_Zinc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MET #phi (N_{jets} #geq 3)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1253" class="blob-line-num js-line-number" data-line-number="1253"></td>
        <td id="LC1253" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1254" class="blob-line-num js-line-number" data-line-number="1254"></td>
        <td id="LC1254" class="blob-line-code js-file-line">    <span class="n">MTEWK_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MTEWK_Zinc2jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MT (N_{jets} #geq 2)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1255" class="blob-line-num js-line-number" data-line-number="1255"></td>
        <td id="LC1255" class="blob-line-code js-file-line">    <span class="n">MTEWK_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MTEWK_Zinc3jet&quot;</span><span class="p">,</span>                      <span class="s">&quot;MT (N_{jets} #geq 3)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1256" class="blob-line-num js-line-number" data-line-number="1256"></td>
        <td id="LC1256" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1257" class="blob-line-num js-line-number" data-line-number="1257"></td>
        <td id="LC1257" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1258" class="blob-line-num js-line-number" data-line-number="1258"></td>
        <td id="LC1258" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1259" class="blob-line-num js-line-number" data-line-number="1259"></td>
        <td id="LC1259" class="blob-line-code js-file-line">    <span class="c1">/// jet properties</span></td>
      </tr>
      <tr>
        <td id="L1260" class="blob-line-num js-line-number" data-line-number="1260"></td>
        <td id="LC1260" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPtEWK_Zinc2jet</span><span class="p">(</span><span class="mi">15</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1261" class="blob-line-num js-line-number" data-line-number="1261"></td>
        <td id="LC1261" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">[</span><span class="mi">16</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">15</span><span class="p">,</span> <span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">38</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">68</span><span class="p">,</span> <span class="mi">88</span><span class="p">,</span> <span class="mi">113</span><span class="p">,</span> <span class="mi">144</span><span class="p">,</span> <span class="mi">184</span><span class="p">,</span> <span class="mi">234</span><span class="p">,</span> <span class="mi">297</span><span class="p">,</span> <span class="mi">377</span><span class="p">,</span> <span class="mi">480</span><span class="p">,</span> <span class="mi">700</span> <span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L1262" class="blob-line-num js-line-number" data-line-number="1262"></td>
        <td id="LC1262" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetPtEWKbtw_Zinc2jet</span><span class="p">(</span><span class="mi">12</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1263" class="blob-line-num js-line-number" data-line-number="1263"></td>
        <td id="LC1263" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetPtEWKbtw_Zinc2jet</span><span class="p">[</span><span class="mi">13</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">15</span><span class="p">,</span> <span class="mi">20</span><span class="p">,</span> <span class="mi">24</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">38</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">68</span><span class="p">,</span> <span class="mi">88</span><span class="p">,</span> <span class="mi">113</span><span class="p">,</span> <span class="mi">144</span><span class="p">,</span> <span class="mi">184</span><span class="p">,</span> <span class="mi">234</span><span class="p">,</span> <span class="mi">297</span> <span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L1264" class="blob-line-num js-line-number" data-line-number="1264"></td>
        <td id="LC1264" class="blob-line-code js-file-line">    <span class="kt">int</span> <span class="nf">nJetHTEWK_Zinc2jet</span><span class="p">(</span><span class="mi">15</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1265" class="blob-line-num js-line-number" data-line-number="1265"></td>
        <td id="LC1265" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHTEWK_Zinc2jet</span><span class="p">[</span><span class="mi">16</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">60</span><span class="p">,</span> <span class="mi">80</span><span class="p">,</span> <span class="mi">95</span><span class="p">,</span> <span class="mi">121</span><span class="p">,</span> <span class="mi">155</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">336</span><span class="p">,</span> <span class="mi">436</span><span class="p">,</span> <span class="mi">566</span><span class="p">,</span> <span class="mi">737</span><span class="p">,</span> <span class="mi">962</span><span class="p">,</span> <span class="mi">1200</span><span class="p">,</span> <span class="mi">1500</span><span class="p">,</span> <span class="mi">2000</span><span class="p">,</span> <span class="mi">2500</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L1266" class="blob-line-num js-line-number" data-line-number="1266"></td>
        <td id="LC1266" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1267" class="blob-line-num js-line-number" data-line-number="1267"></td>
        <td id="LC1267" class="blob-line-code js-file-line">    <span class="n">FirstJetPtEWK_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;1st jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1268" class="blob-line-num js-line-number" data-line-number="1268"></td>
        <td id="LC1268" class="blob-line-code js-file-line">    <span class="n">SecondJetPtEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;2nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1269" class="blob-line-num js-line-number" data-line-number="1269"></td>
        <td id="LC1269" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1270" class="blob-line-num js-line-number" data-line-number="1270"></td>
        <td id="LC1270" class="blob-line-code js-file-line">    <span class="n">FirstJetEtaEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;1st jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1271" class="blob-line-num js-line-number" data-line-number="1271"></td>
        <td id="LC1271" class="blob-line-code js-file-line">    <span class="n">SecondJetEtaEWK_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;2nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1272" class="blob-line-num js-line-number" data-line-number="1272"></td>
        <td id="LC1272" class="blob-line-code js-file-line">    <span class="n">FirstJetPhiEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;1st jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1273" class="blob-line-num js-line-number" data-line-number="1273"></td>
        <td id="LC1273" class="blob-line-code js-file-line">    <span class="n">SecondJetPhiEWK_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;2nd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1274" class="blob-line-num js-line-number" data-line-number="1274"></td>
        <td id="LC1274" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1275" class="blob-line-num js-line-number" data-line-number="1275"></td>
        <td id="LC1275" class="blob-line-code js-file-line">    <span class="n">ForwardJetPtEWK_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ForwardJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;Fwd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1276" class="blob-line-num js-line-number" data-line-number="1276"></td>
        <td id="LC1276" class="blob-line-code js-file-line">    <span class="n">ForwardJetEtaEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ForwardJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Fwd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1277" class="blob-line-num js-line-number" data-line-number="1277"></td>
        <td id="LC1277" class="blob-line-code js-file-line">    <span class="n">ForwardJetPhiEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ForwardJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Fwd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1278" class="blob-line-num js-line-number" data-line-number="1278"></td>
        <td id="LC1278" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1279" class="blob-line-num js-line-number" data-line-number="1279"></td>
        <td id="LC1279" class="blob-line-code js-file-line">    <span class="n">CentralJetPtEWK_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;CentralJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;Cnt jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1280" class="blob-line-num js-line-number" data-line-number="1280"></td>
        <td id="LC1280" class="blob-line-code js-file-line">    <span class="n">CentralJetEtaEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;CentralJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Cnt jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1281" class="blob-line-num js-line-number" data-line-number="1281"></td>
        <td id="LC1281" class="blob-line-code js-file-line">    <span class="n">CentralJetPhiEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;CentralJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Cnt jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1282" class="blob-line-num js-line-number" data-line-number="1282"></td>
        <td id="LC1282" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1283" class="blob-line-num js-line-number" data-line-number="1283"></td>
        <td id="LC1283" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1284" class="blob-line-num js-line-number" data-line-number="1284"></td>
        <td id="LC1284" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1285" class="blob-line-num js-line-number" data-line-number="1285"></td>
        <td id="LC1285" class="blob-line-code js-file-line">    <span class="n">ThirdJetPtEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Ext 3nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1286" class="blob-line-num js-line-number" data-line-number="1286"></td>
        <td id="LC1286" class="blob-line-code js-file-line">    <span class="n">ThirdJetPhiEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;Ext 3nd jet #Phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;#Phi(j_{3}) &quot;</span><span class="p">,</span>     <span class="mi">30</span><span class="p">,</span> <span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1287" class="blob-line-num js-line-number" data-line-number="1287"></td>
        <td id="LC1287" class="blob-line-code js-file-line">    <span class="n">ThirdJetEtaEWK_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Ext 3nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1288" class="blob-line-num js-line-number" data-line-number="1288"></td>
        <td id="LC1288" class="blob-line-code js-file-line">    <span class="c1">/// additional activity &gt; 15 GeV full space</span></td>
      </tr>
      <tr>
        <td id="L1289" class="blob-line-num js-line-number" data-line-number="1289"></td>
        <td id="LC1289" class="blob-line-code js-file-line">    <span class="n">ThirdJetPtEWKadd_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPtEWKadd_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Ext pt#ge 15 3nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1290" class="blob-line-num js-line-number" data-line-number="1290"></td>
        <td id="LC1290" class="blob-line-code js-file-line">    <span class="n">ThirdJetPhiEWKadd_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPhiEWKadd_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Ext 3nd pt#ge 15 jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;#Phi(j_{3}) &quot;</span><span class="p">,</span>     <span class="mi">30</span><span class="p">,</span> <span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1291" class="blob-line-num js-line-number" data-line-number="1291"></td>
        <td id="LC1291" class="blob-line-code js-file-line">    <span class="n">ThirdJetEtaEWKadd_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetEtaEWKadd_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Ext 3nd pt#ge 15 jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1292" class="blob-line-num js-line-number" data-line-number="1292"></td>
        <td id="LC1292" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1293" class="blob-line-num js-line-number" data-line-number="1293"></td>
        <td id="LC1293" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1294" class="blob-line-num js-line-number" data-line-number="1294"></td>
        <td id="LC1294" class="blob-line-code js-file-line">    <span class="c1">/////  dijet properties</span></td>
      </tr>
      <tr>
        <td id="L1295" class="blob-line-num js-line-number" data-line-number="1295"></td>
        <td id="LC1295" class="blob-line-code js-file-line">    <span class="n">string</span> <span class="n">jSEta</span> <span class="o">=</span> <span class="s">&quot;#eta(j_{1})+ #eta(j_{2})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L1296" class="blob-line-num js-line-number" data-line-number="1296"></td>
        <td id="LC1296" class="blob-line-code js-file-line">    <span class="n">SumEtaJetsEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SumEtaJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;|#Sigma| #eta of j1,j2 jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1297" class="blob-line-num js-line-number" data-line-number="1297"></td>
        <td id="LC1297" class="blob-line-code js-file-line">    <span class="n">AbsSumEtaJetsEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AbsSumEtaJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;#Sigma |#eta| of j1,j2 jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1298" class="blob-line-num js-line-number" data-line-number="1298"></td>
        <td id="LC1298" class="blob-line-code js-file-line">    <span class="n">SumEtaJetsEWK_Zinc3jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SumEtaJetsEWK_Zinc3jet&quot;</span><span class="p">,</span>             <span class="s">&quot;sum of #eta of j1,j2 jets (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1299" class="blob-line-num js-line-number" data-line-number="1299"></td>
        <td id="LC1299" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1300" class="blob-line-num js-line-number" data-line-number="1300"></td>
        <td id="LC1300" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1301" class="blob-line-num js-line-number" data-line-number="1301"></td>
        <td id="LC1301" class="blob-line-code js-file-line">    <span class="n">dEtaJetsEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;#Delta#eta btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1302" class="blob-line-num js-line-number" data-line-number="1302"></td>
        <td id="LC1302" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1303" class="blob-line-num js-line-number" data-line-number="1303"></td>
        <td id="LC1303" class="blob-line-code js-file-line">    <span class="n">TwoJetsPtDiffEWK_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TwoJetsPtDiffEWK_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                             <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">500</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1304" class="blob-line-num js-line-number" data-line-number="1304"></td>
        <td id="LC1304" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1305" class="blob-line-num js-line-number" data-line-number="1305"></td>
        <td id="LC1305" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1306" class="blob-line-num js-line-number" data-line-number="1306"></td>
        <td id="LC1306" class="blob-line-code js-file-line">    <span class="n">ptBalEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBalEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                       <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">500</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1307" class="blob-line-num js-line-number" data-line-number="1307"></td>
        <td id="LC1307" class="blob-line-code js-file-line">    <span class="n">SpTJetsEWK_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;#Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1308" class="blob-line-num js-line-number" data-line-number="1308"></td>
        <td id="LC1308" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1309" class="blob-line-num js-line-number" data-line-number="1309"></td>
        <td id="LC1309" class="blob-line-code js-file-line">    <span class="n">dPhiJetsEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;#Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">100</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1310" class="blob-line-num js-line-number" data-line-number="1310"></td>
        <td id="LC1310" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1311" class="blob-line-num js-line-number" data-line-number="1311"></td>
        <td id="LC1311" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1312" class="blob-line-num js-line-number" data-line-number="1312"></td>
        <td id="LC1312" class="blob-line-code js-file-line">    <span class="n">JetsHTEWK_Zinc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHTEWK_Zinc2jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHTEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1313" class="blob-line-num js-line-number" data-line-number="1313"></td>
        <td id="LC1313" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1314" class="blob-line-num js-line-number" data-line-number="1314"></td>
        <td id="LC1314" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1315" class="blob-line-num js-line-number" data-line-number="1315"></td>
        <td id="LC1315" class="blob-line-code js-file-line">    <span class="n">JetsMassEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsMassEWK_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">Mjj</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">20</span><span class="p">,</span> <span class="mi">2620</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1316" class="blob-line-num js-line-number" data-line-number="1316"></td>
        <td id="LC1316" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1317" class="blob-line-num js-line-number" data-line-number="1317"></td>
        <td id="LC1317" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1318" class="blob-line-num js-line-number" data-line-number="1318"></td>
        <td id="LC1318" class="blob-line-code js-file-line">    <span class="c1">//// third jet properties</span></td>
      </tr>
      <tr>
        <td id="L1319" class="blob-line-num js-line-number" data-line-number="1319"></td>
        <td id="LC1319" class="blob-line-code js-file-line">    <span class="n">string</span>  <span class="n">j3Eta</span> <span class="o">=</span> <span class="s">&quot;#eta(j_{3})&quot;</span><span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L1320" class="blob-line-num js-line-number" data-line-number="1320"></td>
        <td id="LC1320" class="blob-line-code js-file-line">    <span class="n">EtaThirdJetsEWK_Zinc3jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;EtaThirdJetsEWK_Zinc3jet&quot;</span><span class="p">,</span>             <span class="s">&quot;Third jet #eta in dijet frame (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                                       <span class="n">j3Eta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1321" class="blob-line-num js-line-number" data-line-number="1321"></td>
        <td id="LC1321" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1322" class="blob-line-num js-line-number" data-line-number="1322"></td>
        <td id="LC1322" class="blob-line-code js-file-line">    <span class="c1">/// all jets between leading two jets </span></td>
      </tr>
      <tr>
        <td id="L1323" class="blob-line-num js-line-number" data-line-number="1323"></td>
        <td id="LC1323" class="blob-line-code js-file-line">    <span class="n">AllJetPtEWKbtw_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPtEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Ext,btw All jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWKbtw_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWKbtw_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1324" class="blob-line-num js-line-number" data-line-number="1324"></td>
        <td id="LC1324" class="blob-line-code js-file-line">    <span class="n">AllJetPhiEWKbtw_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetPhiEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Ext,btw All jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1325" class="blob-line-num js-line-number" data-line-number="1325"></td>
        <td id="LC1325" class="blob-line-code js-file-line">    <span class="n">AllJetEtaEWKbtw_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;AllJetEtaEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Ext,btw All jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1326" class="blob-line-num js-line-number" data-line-number="1326"></td>
        <td id="LC1326" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">jetHTEWKbtw_Zinc2jet</span><span class="p">[</span><span class="mi">16</span><span class="p">]</span> <span class="o">=</span> <span class="p">{</span><span class="mi">0</span><span class="p">,</span><span class="mi">15</span><span class="p">,</span> <span class="mi">20</span><span class="p">,</span> <span class="mi">30</span><span class="p">,</span> <span class="mi">42</span><span class="p">,</span> <span class="mi">60</span><span class="p">,</span> <span class="mi">80</span><span class="p">,</span> <span class="mi">95</span><span class="p">,</span> <span class="mi">121</span><span class="p">,</span> <span class="mi">155</span><span class="p">,</span> <span class="mi">200</span><span class="p">,</span> <span class="mi">260</span><span class="p">,</span> <span class="mi">336</span><span class="p">,</span> <span class="mi">436</span><span class="p">,</span> <span class="mi">566</span><span class="p">,</span> <span class="mi">737</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L1327" class="blob-line-num js-line-number" data-line-number="1327"></td>
        <td id="LC1327" class="blob-line-code js-file-line">    <span class="n">JetsHTEWKbtw_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHTEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Ext,btw Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHTEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWKbtw_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1328" class="blob-line-num js-line-number" data-line-number="1328"></td>
        <td id="LC1328" class="blob-line-code js-file-line">    <span class="c1">//TH1D *JetsHTEWKbtw_Zinc2jet                     = newTH1D(&quot;JetsHTEWKbtw_Zinc2jet&quot;,                     &quot;Ext,btw Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;,     HT,     nJetHTEWK_Zinc2jet, jetHTEWK_Zinc2jet);</span></td>
      </tr>
      <tr>
        <td id="L1329" class="blob-line-num js-line-number" data-line-number="1329"></td>
        <td id="LC1329" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1330" class="blob-line-num js-line-number" data-line-number="1330"></td>
        <td id="LC1330" class="blob-line-code js-file-line">    <span class="c1">// third jet between</span></td>
      </tr>
      <tr>
        <td id="L1331" class="blob-line-num js-line-number" data-line-number="1331"></td>
        <td id="LC1331" class="blob-line-code js-file-line">    <span class="n">ThirdJetPtEWKbtw_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPtEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Ext,btw 3nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1332" class="blob-line-num js-line-number" data-line-number="1332"></td>
        <td id="LC1332" class="blob-line-code js-file-line">    <span class="n">ThirdJetPhiEWKbtw_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPhiEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Ext,btw 3nd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1333" class="blob-line-num js-line-number" data-line-number="1333"></td>
        <td id="LC1333" class="blob-line-code js-file-line">    <span class="n">ThirdJetEtaEWKbtw_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetEtaEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Ext,btw 3nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1334" class="blob-line-num js-line-number" data-line-number="1334"></td>
        <td id="LC1334" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1335" class="blob-line-num js-line-number" data-line-number="1335"></td>
        <td id="LC1335" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1336" class="blob-line-num js-line-number" data-line-number="1336"></td>
        <td id="LC1336" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZNGoodJetsEWK_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1337" class="blob-line-num js-line-number" data-line-number="1337"></td>
        <td id="LC1337" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1338" class="blob-line-num js-line-number" data-line-number="1338"></td>
        <td id="LC1338" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1339" class="blob-line-num js-line-number" data-line-number="1339"></td>
        <td id="LC1339" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1340" class="blob-line-num js-line-number" data-line-number="1340"></td>
        <td id="LC1340" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1341" class="blob-line-num js-line-number" data-line-number="1341"></td>
        <td id="LC1341" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1342" class="blob-line-num js-line-number" data-line-number="1342"></td>
        <td id="LC1342" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1343" class="blob-line-num js-line-number" data-line-number="1343"></td>
        <td id="LC1343" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1344" class="blob-line-num js-line-number" data-line-number="1344"></td>
        <td id="LC1344" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1345" class="blob-line-num js-line-number" data-line-number="1345"></td>
        <td id="LC1345" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;= 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1346" class="blob-line-num js-line-number" data-line-number="1346"></td>
        <td id="LC1346" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;= 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1347" class="blob-line-num js-line-number" data-line-number="1347"></td>
        <td id="LC1347" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;= 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1348" class="blob-line-num js-line-number" data-line-number="1348"></td>
        <td id="LC1348" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genZNGoodJetsEWKbtw_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;Between: Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1349" class="blob-line-num js-line-number" data-line-number="1349"></td>
        <td id="LC1349" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1350" class="blob-line-num js-line-number" data-line-number="1350"></td>
        <td id="LC1350" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1351" class="blob-line-num js-line-number" data-line-number="1351"></td>
        <td id="LC1351" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1352" class="blob-line-num js-line-number" data-line-number="1352"></td>
        <td id="LC1352" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1353" class="blob-line-num js-line-number" data-line-number="1353"></td>
        <td id="LC1353" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1354" class="blob-line-num js-line-number" data-line-number="1354"></td>
        <td id="LC1354" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1355" class="blob-line-num js-line-number" data-line-number="1355"></td>
        <td id="LC1355" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1356" class="blob-line-num js-line-number" data-line-number="1356"></td>
        <td id="LC1356" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1357" class="blob-line-num js-line-number" data-line-number="1357"></td>
        <td id="LC1357" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;= 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1358" class="blob-line-num js-line-number" data-line-number="1358"></td>
        <td id="LC1358" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;= 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1359" class="blob-line-num js-line-number" data-line-number="1359"></td>
        <td id="LC1359" class="blob-line-code js-file-line">    <span class="n">genZNGoodJetsEWKbtw_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;= 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1360" class="blob-line-num js-line-number" data-line-number="1360"></td>
        <td id="LC1360" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1361" class="blob-line-num js-line-number" data-line-number="1361"></td>
        <td id="LC1361" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1362" class="blob-line-num js-line-number" data-line-number="1362"></td>
        <td id="LC1362" class="blob-line-code js-file-line">    <span class="n">genFirstJetPtEWK_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;Gen:1st jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1363" class="blob-line-num js-line-number" data-line-number="1363"></td>
        <td id="LC1363" class="blob-line-code js-file-line">    <span class="n">genSecondJetPtEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:2nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1364" class="blob-line-num js-line-number" data-line-number="1364"></td>
        <td id="LC1364" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1365" class="blob-line-num js-line-number" data-line-number="1365"></td>
        <td id="LC1365" class="blob-line-code js-file-line">    <span class="n">genFirstJetEtaEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:1st jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1366" class="blob-line-num js-line-number" data-line-number="1366"></td>
        <td id="LC1366" class="blob-line-code js-file-line">    <span class="n">genSecondJetEtaEWK_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Gen:2nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#eta(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1367" class="blob-line-num js-line-number" data-line-number="1367"></td>
        <td id="LC1367" class="blob-line-code js-file-line">    <span class="n">genFirstJetPhiEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genFirstJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:1st jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1368" class="blob-line-num js-line-number" data-line-number="1368"></td>
        <td id="LC1368" class="blob-line-code js-file-line">    <span class="n">genSecondJetPhiEWK_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSecondJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Gen:2nd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#phi(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1369" class="blob-line-num js-line-number" data-line-number="1369"></td>
        <td id="LC1369" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1370" class="blob-line-num js-line-number" data-line-number="1370"></td>
        <td id="LC1370" class="blob-line-code js-file-line">    <span class="n">genForwardJetPtEWK_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genForwardJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;Gen:Fwd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1371" class="blob-line-num js-line-number" data-line-number="1371"></td>
        <td id="LC1371" class="blob-line-code js-file-line">    <span class="n">genForwardJetEtaEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genForwardJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Fwd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1372" class="blob-line-num js-line-number" data-line-number="1372"></td>
        <td id="LC1372" class="blob-line-code js-file-line">    <span class="n">genForwardJetPhiEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genForwardJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Fwd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1373" class="blob-line-num js-line-number" data-line-number="1373"></td>
        <td id="LC1373" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1374" class="blob-line-num js-line-number" data-line-number="1374"></td>
        <td id="LC1374" class="blob-line-code js-file-line">    <span class="n">genCentralJetPtEWK_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genCentralJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                 <span class="s">&quot;Gen:Cnt jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1375" class="blob-line-num js-line-number" data-line-number="1375"></td>
        <td id="LC1375" class="blob-line-code js-file-line">    <span class="n">genCentralJetEtaEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genCentralJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Cnt jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1376" class="blob-line-num js-line-number" data-line-number="1376"></td>
        <td id="LC1376" class="blob-line-code js-file-line">    <span class="n">genCentralJetPhiEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genCentralJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Cnt jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1377" class="blob-line-num js-line-number" data-line-number="1377"></td>
        <td id="LC1377" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1378" class="blob-line-num js-line-number" data-line-number="1378"></td>
        <td id="LC1378" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1379" class="blob-line-num js-line-number" data-line-number="1379"></td>
        <td id="LC1379" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1380" class="blob-line-num js-line-number" data-line-number="1380"></td>
        <td id="LC1380" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1381" class="blob-line-num js-line-number" data-line-number="1381"></td>
        <td id="LC1381" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1382" class="blob-line-num js-line-number" data-line-number="1382"></td>
        <td id="LC1382" class="blob-line-code js-file-line">    <span class="n">genThirdJetPtEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPtEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Ext 3nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1383" class="blob-line-num js-line-number" data-line-number="1383"></td>
        <td id="LC1383" class="blob-line-code js-file-line">    <span class="n">genThirdJetPhiEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPhiEWK_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:Ext 3nd jet #Phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:#Phi(j_{3}) &quot;</span><span class="p">,</span>     <span class="mi">30</span><span class="p">,</span> <span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1384" class="blob-line-num js-line-number" data-line-number="1384"></td>
        <td id="LC1384" class="blob-line-code js-file-line">    <span class="n">genThirdJetEtaEWK_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetEtaEWK_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Gen:Ext 3nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1385" class="blob-line-num js-line-number" data-line-number="1385"></td>
        <td id="LC1385" class="blob-line-code js-file-line">    <span class="c1">/// additional activity &gt; 15 GeV full space</span></td>
      </tr>
      <tr>
        <td id="L1386" class="blob-line-num js-line-number" data-line-number="1386"></td>
        <td id="LC1386" class="blob-line-code js-file-line">    <span class="n">genThirdJetPtEWKadd_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPtEWKadd_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Ext pt#ge 15 3nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1387" class="blob-line-num js-line-number" data-line-number="1387"></td>
        <td id="LC1387" class="blob-line-code js-file-line">    <span class="n">genThirdJetPhiEWKadd_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPhiEWKadd_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Ext 3nd pt#ge 15 jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:#Phi(j_{3}) &quot;</span><span class="p">,</span>     <span class="mi">30</span><span class="p">,</span> <span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1388" class="blob-line-num js-line-number" data-line-number="1388"></td>
        <td id="LC1388" class="blob-line-code js-file-line">    <span class="n">genThirdJetEtaEWKadd_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetEtaEWKadd_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Gen:Ext 3nd pt#ge 15 jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1389" class="blob-line-num js-line-number" data-line-number="1389"></td>
        <td id="LC1389" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1390" class="blob-line-num js-line-number" data-line-number="1390"></td>
        <td id="LC1390" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1391" class="blob-line-num js-line-number" data-line-number="1391"></td>
        <td id="LC1391" class="blob-line-code js-file-line">    <span class="c1">/////  dijet properties</span></td>
      </tr>
      <tr>
        <td id="L1392" class="blob-line-num js-line-number" data-line-number="1392"></td>
        <td id="LC1392" class="blob-line-code js-file-line">    <span class="c1">//string jSEta = &quot;#eta(j_{1})+ #eta(j_{2})&quot;;</span></td>
      </tr>
      <tr>
        <td id="L1393" class="blob-line-num js-line-number" data-line-number="1393"></td>
        <td id="LC1393" class="blob-line-code js-file-line">    <span class="n">genSumEtaJetsEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSumEtaJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:|#Sigma| #eta of j1,j2 jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1394" class="blob-line-num js-line-number" data-line-number="1394"></td>
        <td id="LC1394" class="blob-line-code js-file-line">    <span class="n">genAbsSumEtaJetsEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genAbsSumEtaJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;Gen:#Sigma |#eta| of j1,j2 jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1395" class="blob-line-num js-line-number" data-line-number="1395"></td>
        <td id="LC1395" class="blob-line-code js-file-line">    <span class="n">genSumEtaJetsEWK_Zinc3jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSumEtaJetsEWK_Zinc3jet&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:sum of #eta of j1,j2 jets (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1396" class="blob-line-num js-line-number" data-line-number="1396"></td>
        <td id="LC1396" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1397" class="blob-line-num js-line-number" data-line-number="1397"></td>
        <td id="LC1397" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1398" class="blob-line-num js-line-number" data-line-number="1398"></td>
        <td id="LC1398" class="blob-line-code js-file-line">    <span class="n">gendEtaJetsEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:#Delta#eta btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1399" class="blob-line-num js-line-number" data-line-number="1399"></td>
        <td id="LC1399" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1400" class="blob-line-num js-line-number" data-line-number="1400"></td>
        <td id="LC1400" class="blob-line-code js-file-line">    <span class="n">genTwoJetsPtDiffEWK_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genTwoJetsPtDiffEWK_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;Gen:pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                             <span class="s">&quot;Gen:#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">500</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1401" class="blob-line-num js-line-number" data-line-number="1401"></td>
        <td id="LC1401" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1402" class="blob-line-num js-line-number" data-line-number="1402"></td>
        <td id="LC1402" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1403" class="blob-line-num js-line-number" data-line-number="1403"></td>
        <td id="LC1403" class="blob-line-code js-file-line">    <span class="n">genptBalEWK_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genptBalEWK_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Vectorial pT sum: Z_{pT} + DiJet_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                       <span class="s">&quot;Gen:#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">500</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1404" class="blob-line-num js-line-number" data-line-number="1404"></td>
        <td id="LC1404" class="blob-line-code js-file-line">    <span class="n">genSpTJetsEWK_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1405" class="blob-line-num js-line-number" data-line-number="1405"></td>
        <td id="LC1405" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1406" class="blob-line-num js-line-number" data-line-number="1406"></td>
        <td id="LC1406" class="blob-line-code js-file-line">    <span class="n">gendPhiJetsEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJetsEWK_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:#Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">100</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1407" class="blob-line-num js-line-number" data-line-number="1407"></td>
        <td id="LC1407" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1408" class="blob-line-num js-line-number" data-line-number="1408"></td>
        <td id="LC1408" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1409" class="blob-line-num js-line-number" data-line-number="1409"></td>
        <td id="LC1409" class="blob-line-code js-file-line">    <span class="n">genJetsHTEWK_Zinc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHTEWK_Zinc2jet&quot;</span><span class="p">,</span>                     <span class="s">&quot;Gen:Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHTEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1410" class="blob-line-num js-line-number" data-line-number="1410"></td>
        <td id="LC1410" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1411" class="blob-line-num js-line-number" data-line-number="1411"></td>
        <td id="LC1411" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1412" class="blob-line-num js-line-number" data-line-number="1412"></td>
        <td id="LC1412" class="blob-line-code js-file-line">    <span class="n">genJetsMassEWK_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsMassEWK_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">Mjj</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">20</span><span class="p">,</span> <span class="mi">2620</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1413" class="blob-line-num js-line-number" data-line-number="1413"></td>
        <td id="LC1413" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1414" class="blob-line-num js-line-number" data-line-number="1414"></td>
        <td id="LC1414" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1415" class="blob-line-num js-line-number" data-line-number="1415"></td>
        <td id="LC1415" class="blob-line-code js-file-line">    <span class="c1">//// third jet properties</span></td>
      </tr>
      <tr>
        <td id="L1416" class="blob-line-num js-line-number" data-line-number="1416"></td>
        <td id="LC1416" class="blob-line-code js-file-line">    <span class="c1">//string  j3Eta = &quot;#eta(j_{3})&quot;;</span></td>
      </tr>
      <tr>
        <td id="L1417" class="blob-line-num js-line-number" data-line-number="1417"></td>
        <td id="LC1417" class="blob-line-code js-file-line">    <span class="n">genEtaThirdJetsEWK_Zinc3jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genEtaThirdJetsEWK_Zinc3jet&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:Third jet #eta in dijet frame (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                                       <span class="n">j3Eta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1418" class="blob-line-num js-line-number" data-line-number="1418"></td>
        <td id="LC1418" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1419" class="blob-line-num js-line-number" data-line-number="1419"></td>
        <td id="LC1419" class="blob-line-code js-file-line">    <span class="c1">/// all jets between leading two jets </span></td>
      </tr>
      <tr>
        <td id="L1420" class="blob-line-num js-line-number" data-line-number="1420"></td>
        <td id="LC1420" class="blob-line-code js-file-line">    <span class="n">genAllJetPtEWKbtw_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genAllJetPtEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Ext,btw All jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWKbtw_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWKbtw_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1421" class="blob-line-num js-line-number" data-line-number="1421"></td>
        <td id="LC1421" class="blob-line-code js-file-line">    <span class="n">genAllJetPhiEWKbtw_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genAllJetPhiEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Gen:Ext,btw All jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#phi(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1422" class="blob-line-num js-line-number" data-line-number="1422"></td>
        <td id="LC1422" class="blob-line-code js-file-line">    <span class="n">genAllJetEtaEWKbtw_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genAllJetEtaEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Gen:Ext,btw All jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1423" class="blob-line-num js-line-number" data-line-number="1423"></td>
        <td id="LC1423" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1424" class="blob-line-num js-line-number" data-line-number="1424"></td>
        <td id="LC1424" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1425" class="blob-line-num js-line-number" data-line-number="1425"></td>
        <td id="LC1425" class="blob-line-code js-file-line">    <span class="c1">//double jetHTEWKbtw_Zinc2jet[16] = {0,15, 20, 30, 42, 60, 80, 95, 121, 155, 200, 260, 336, 436, 566, 737};</span></td>
      </tr>
      <tr>
        <td id="L1426" class="blob-line-num js-line-number" data-line-number="1426"></td>
        <td id="LC1426" class="blob-line-code js-file-line">    <span class="n">genJetsHTEWKbtw_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHTEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;Gen:Ext,btw Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHTEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWKbtw_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1427" class="blob-line-num js-line-number" data-line-number="1427"></td>
        <td id="LC1427" class="blob-line-code js-file-line">    <span class="c1">//TH1D *genJetsHTEWKbtw_Zinc2jet                     = newTH1D(&quot;genJetsHTEWKbtw_Zinc2jet&quot;,                     &quot;Gen:Ext,btw Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;,     HT,     nJetHTEWK_Zinc2jet, jetHTEWK_Zinc2jet);</span></td>
      </tr>
      <tr>
        <td id="L1428" class="blob-line-num js-line-number" data-line-number="1428"></td>
        <td id="LC1428" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1429" class="blob-line-num js-line-number" data-line-number="1429"></td>
        <td id="LC1429" class="blob-line-code js-file-line">    <span class="c1">// third jet between</span></td>
      </tr>
      <tr>
        <td id="L1430" class="blob-line-num js-line-number" data-line-number="1430"></td>
        <td id="LC1430" class="blob-line-code js-file-line">    <span class="n">genThirdJetPtEWKbtw_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPtEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>                <span class="s">&quot;Gen:Ext,btw 3nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;Gen:p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1431" class="blob-line-num js-line-number" data-line-number="1431"></td>
        <td id="LC1431" class="blob-line-code js-file-line">    <span class="n">genThirdJetPhiEWKbtw_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetPhiEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Gen:Ext,btw 3nd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#phi(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1432" class="blob-line-num js-line-number" data-line-number="1432"></td>
        <td id="LC1432" class="blob-line-code js-file-line">    <span class="n">genThirdJetEtaEWKbtw_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genThirdJetEtaEWKbtw_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;Gen:Ext,btw 3nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;Gen:#eta(j_{3})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1433" class="blob-line-num js-line-number" data-line-number="1433"></td>
        <td id="LC1433" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1434" class="blob-line-num js-line-number" data-line-number="1434"></td>
        <td id="LC1434" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1435" class="blob-line-num js-line-number" data-line-number="1435"></td>
        <td id="LC1435" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1436" class="blob-line-num js-line-number" data-line-number="1436"></td>
        <td id="LC1436" class="blob-line-code js-file-line">    <span class="c1">//// at least one forward jet</span></td>
      </tr>
      <tr>
        <td id="L1437" class="blob-line-num js-line-number" data-line-number="1437"></td>
        <td id="LC1437" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKfwd_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJetsEWKfwd_Zexc&quot;</span><span class="p">,</span><span class="s">&quot; 1 Fwd jet: Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1438" class="blob-line-num js-line-number" data-line-number="1438"></td>
        <td id="LC1438" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1439" class="blob-line-num js-line-number" data-line-number="1439"></td>
        <td id="LC1439" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1440" class="blob-line-num js-line-number" data-line-number="1440"></td>
        <td id="LC1440" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1441" class="blob-line-num js-line-number" data-line-number="1441"></td>
        <td id="LC1441" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1442" class="blob-line-num js-line-number" data-line-number="1442"></td>
        <td id="LC1442" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1443" class="blob-line-num js-line-number" data-line-number="1443"></td>
        <td id="LC1443" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1444" class="blob-line-num js-line-number" data-line-number="1444"></td>
        <td id="LC1444" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1445" class="blob-line-num js-line-number" data-line-number="1445"></td>
        <td id="LC1445" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1446" class="blob-line-num js-line-number" data-line-number="1446"></td>
        <td id="LC1446" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;= 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1447" class="blob-line-num js-line-number" data-line-number="1447"></td>
        <td id="LC1447" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;= 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1448" class="blob-line-num js-line-number" data-line-number="1448"></td>
        <td id="LC1448" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;= 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1449" class="blob-line-num js-line-number" data-line-number="1449"></td>
        <td id="LC1449" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1450" class="blob-line-num js-line-number" data-line-number="1450"></td>
        <td id="LC1450" class="blob-line-code js-file-line">    <span class="c1">// met properties</span></td>
      </tr>
      <tr>
        <td id="L1451" class="blob-line-num js-line-number" data-line-number="1451"></td>
        <td id="LC1451" class="blob-line-code js-file-line">    <span class="n">METEWKfwd_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot; 1 Fwd jet: MET (N_{jets} #geq 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">500</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1452" class="blob-line-num js-line-number" data-line-number="1452"></td>
        <td id="LC1452" class="blob-line-code js-file-line">    <span class="n">METEWKfwd_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METEWKfwd_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot; 1 Fwd jet: MET (N_{jets} #geq 3)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">500</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1453" class="blob-line-num js-line-number" data-line-number="1453"></td>
        <td id="LC1453" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1454" class="blob-line-num js-line-number" data-line-number="1454"></td>
        <td id="LC1454" class="blob-line-code js-file-line">    <span class="n">METphiEWKfwd_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphiEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot; 1 Fwd jet: MET #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1455" class="blob-line-num js-line-number" data-line-number="1455"></td>
        <td id="LC1455" class="blob-line-code js-file-line">    <span class="n">METphiEWKfwd_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphiEWKfwd_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot; 1 Fwd jet: MET #phi (N_{jets} #geq 3)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1456" class="blob-line-num js-line-number" data-line-number="1456"></td>
        <td id="LC1456" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1457" class="blob-line-num js-line-number" data-line-number="1457"></td>
        <td id="LC1457" class="blob-line-code js-file-line">    <span class="n">MTEWKfwd_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MTEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot; 1 Fwd jet: MT (N_{jets} #geq 2)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1458" class="blob-line-num js-line-number" data-line-number="1458"></td>
        <td id="LC1458" class="blob-line-code js-file-line">    <span class="n">MTEWKfwd_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MTEWKfwd_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot; 1 Fwd jet: MT (N_{jets} #geq 3)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1459" class="blob-line-num js-line-number" data-line-number="1459"></td>
        <td id="LC1459" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1460" class="blob-line-num js-line-number" data-line-number="1460"></td>
        <td id="LC1460" class="blob-line-code js-file-line">    <span class="c1">// jet hisotgrams</span></td>
      </tr>
      <tr>
        <td id="L1461" class="blob-line-num js-line-number" data-line-number="1461"></td>
        <td id="LC1461" class="blob-line-code js-file-line">    <span class="n">FirstJetPtEWKfwd_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPtEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot; 1 Fwd jet: 1st jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1462" class="blob-line-num js-line-number" data-line-number="1462"></td>
        <td id="LC1462" class="blob-line-code js-file-line">    <span class="n">SecondJetPtEWKfwd_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPtEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot; 1 Fwd jet: 2nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1463" class="blob-line-num js-line-number" data-line-number="1463"></td>
        <td id="LC1463" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1464" class="blob-line-num js-line-number" data-line-number="1464"></td>
        <td id="LC1464" class="blob-line-code js-file-line">    <span class="n">FirstJetEtaEWKfwd_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetEtaEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot; 1 Fwd jet: 1st jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1465" class="blob-line-num js-line-number" data-line-number="1465"></td>
        <td id="LC1465" class="blob-line-code js-file-line">    <span class="n">SecondJetEtaEWKfwd_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetEtaEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot; 1 Fwd jet: 2nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1466" class="blob-line-num js-line-number" data-line-number="1466"></td>
        <td id="LC1466" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1467" class="blob-line-num js-line-number" data-line-number="1467"></td>
        <td id="LC1467" class="blob-line-code js-file-line">    <span class="n">FirstJetPhiEWKfwd_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPhiEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot; 1 Fwd jet: 1st jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1468" class="blob-line-num js-line-number" data-line-number="1468"></td>
        <td id="LC1468" class="blob-line-code js-file-line">    <span class="n">SecondJetPhiEWKfwd_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPhiEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot; 1 Fwd jet: 2nd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1469" class="blob-line-num js-line-number" data-line-number="1469"></td>
        <td id="LC1469" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1470" class="blob-line-num js-line-number" data-line-number="1470"></td>
        <td id="LC1470" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1471" class="blob-line-num js-line-number" data-line-number="1471"></td>
        <td id="LC1471" class="blob-line-code js-file-line">    <span class="n">SumEtaJetsEWKfwd_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SumEtaJetsEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot; 1 Fwd jet: sum of #eta of j1,j2 jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1472" class="blob-line-num js-line-number" data-line-number="1472"></td>
        <td id="LC1472" class="blob-line-code js-file-line">    <span class="n">SumEtaJetsEWKfwd_Zinc3jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SumEtaJetsEWKfwd_Zinc3jet&quot;</span><span class="p">,</span>          <span class="s">&quot; 1 Fwd jet: sum of #eta of j1,j2 jets (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1473" class="blob-line-num js-line-number" data-line-number="1473"></td>
        <td id="LC1473" class="blob-line-code js-file-line">    <span class="n">genSumEtaJetsEWKfwd_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSumEtaJetsEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot; 1 Fwd jet: gen sum of #eta of j1,j2 jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1474" class="blob-line-num js-line-number" data-line-number="1474"></td>
        <td id="LC1474" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1475" class="blob-line-num js-line-number" data-line-number="1475"></td>
        <td id="LC1475" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1476" class="blob-line-num js-line-number" data-line-number="1476"></td>
        <td id="LC1476" class="blob-line-code js-file-line">    <span class="n">dEtaJetsEWKfwd_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaJetsEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot; 1 Fwd jet: #Delta#eta btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1477" class="blob-line-num js-line-number" data-line-number="1477"></td>
        <td id="LC1477" class="blob-line-code js-file-line">    <span class="n">gendEtaJetsEWKfwd_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaJetsEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot; 1 Fwd jet: gen #Delta#eta btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1478" class="blob-line-num js-line-number" data-line-number="1478"></td>
        <td id="LC1478" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1479" class="blob-line-num js-line-number" data-line-number="1479"></td>
        <td id="LC1479" class="blob-line-code js-file-line">    <span class="n">TwoJetsPtDiffEWKfwd_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TwoJetsPtDiffEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot; 1 Fwd jet: pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                             <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">500</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1480" class="blob-line-num js-line-number" data-line-number="1480"></td>
        <td id="LC1480" class="blob-line-code js-file-line">    <span class="n">genTwoJetsPtDiffEWKfwd_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genTwoJetsPtDiffEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot; 1 Fwd jet: gen pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                         <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1000</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1481" class="blob-line-num js-line-number" data-line-number="1481"></td>
        <td id="LC1481" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1482" class="blob-line-num js-line-number" data-line-number="1482"></td>
        <td id="LC1482" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1483" class="blob-line-num js-line-number" data-line-number="1483"></td>
        <td id="LC1483" class="blob-line-code js-file-line">    <span class="n">ptBalEWKfwd_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBalEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot; 1 Fwd jet: Vectorial pT sum: Z_{pT} + Jets_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                       <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">500</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1484" class="blob-line-num js-line-number" data-line-number="1484"></td>
        <td id="LC1484" class="blob-line-code js-file-line">    <span class="n">SpTJetsEWKfwd_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJetsEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot; 1 Fwd jet: #Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1485" class="blob-line-num js-line-number" data-line-number="1485"></td>
        <td id="LC1485" class="blob-line-code js-file-line">    <span class="n">genSpTJetsEWKfwd_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJetsEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot; 1 Fwd jet: gen #Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                            <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1486" class="blob-line-num js-line-number" data-line-number="1486"></td>
        <td id="LC1486" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1487" class="blob-line-num js-line-number" data-line-number="1487"></td>
        <td id="LC1487" class="blob-line-code js-file-line">    <span class="n">dPhiJetsEWKfwd_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJetsEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot; 1 Fwd jet: #Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">100</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1488" class="blob-line-num js-line-number" data-line-number="1488"></td>
        <td id="LC1488" class="blob-line-code js-file-line">    <span class="n">gendPhiJetsEWKfwd_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJetsEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot; 1 Fwd jet: gen #Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">100</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1489" class="blob-line-num js-line-number" data-line-number="1489"></td>
        <td id="LC1489" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1490" class="blob-line-num js-line-number" data-line-number="1490"></td>
        <td id="LC1490" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1491" class="blob-line-num js-line-number" data-line-number="1491"></td>
        <td id="LC1491" class="blob-line-code js-file-line">    <span class="n">JetsHTEWKfwd_Zinc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHTEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot; 1 Fwd jet: Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHTEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1492" class="blob-line-num js-line-number" data-line-number="1492"></td>
        <td id="LC1492" class="blob-line-code js-file-line">    <span class="n">genJetsHTEWKfwd_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHTEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot; 1 Fwd jet: Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHTEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1493" class="blob-line-num js-line-number" data-line-number="1493"></td>
        <td id="LC1493" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1494" class="blob-line-num js-line-number" data-line-number="1494"></td>
        <td id="LC1494" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1495" class="blob-line-num js-line-number" data-line-number="1495"></td>
        <td id="LC1495" class="blob-line-code js-file-line">    <span class="n">JetsMassEWKfwd_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsMassEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot; 1 Fwd jet: 2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">Mjj</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">20</span><span class="p">,</span> <span class="mi">2620</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1496" class="blob-line-num js-line-number" data-line-number="1496"></td>
        <td id="LC1496" class="blob-line-code js-file-line">    <span class="n">genJetsMassEWKfwd_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsMassEWKfwd_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot; 1 Fwd jet: gen 2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">Mjj</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">20</span><span class="p">,</span> <span class="mi">2620</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1497" class="blob-line-num js-line-number" data-line-number="1497"></td>
        <td id="LC1497" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1498" class="blob-line-num js-line-number" data-line-number="1498"></td>
        <td id="LC1498" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1499" class="blob-line-num js-line-number" data-line-number="1499"></td>
        <td id="LC1499" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1500" class="blob-line-num js-line-number" data-line-number="1500"></td>
        <td id="LC1500" class="blob-line-code js-file-line">    <span class="c1">//// at least one forward jet</span></td>
      </tr>
      <tr>
        <td id="L1501" class="blob-line-num js-line-number" data-line-number="1501"></td>
        <td id="LC1501" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWKmjj_Zexc</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ZNGoodJetsEWKmjj_Zexc&quot;</span><span class="p">,</span><span class="s">&quot;M_{jj} #geq 1 TeV: Jet Counter (excl.)&quot;</span><span class="p">,</span> <span class="s">&quot;N_{jets}&quot;</span><span class="p">,</span> <span class="mi">11</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">10.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1502" class="blob-line-num js-line-number" data-line-number="1502"></td>
        <td id="LC1502" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="s">&quot;= 0&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1503" class="blob-line-num js-line-number" data-line-number="1503"></td>
        <td id="LC1503" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">2</span><span class="p">,</span> <span class="s">&quot;= 1&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1504" class="blob-line-num js-line-number" data-line-number="1504"></td>
        <td id="LC1504" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">3</span><span class="p">,</span> <span class="s">&quot;= 2&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1505" class="blob-line-num js-line-number" data-line-number="1505"></td>
        <td id="LC1505" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">4</span><span class="p">,</span> <span class="s">&quot;= 3&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1506" class="blob-line-num js-line-number" data-line-number="1506"></td>
        <td id="LC1506" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">5</span><span class="p">,</span> <span class="s">&quot;= 4&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1507" class="blob-line-num js-line-number" data-line-number="1507"></td>
        <td id="LC1507" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">6</span><span class="p">,</span> <span class="s">&quot;= 5&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1508" class="blob-line-num js-line-number" data-line-number="1508"></td>
        <td id="LC1508" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">7</span><span class="p">,</span> <span class="s">&quot;= 6&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1509" class="blob-line-num js-line-number" data-line-number="1509"></td>
        <td id="LC1509" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">8</span><span class="p">,</span> <span class="s">&quot;= 7&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1510" class="blob-line-num js-line-number" data-line-number="1510"></td>
        <td id="LC1510" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">9</span><span class="p">,</span> <span class="s">&quot;= 8&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1511" class="blob-line-num js-line-number" data-line-number="1511"></td>
        <td id="LC1511" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">10</span><span class="p">,</span><span class="s">&quot;= 9&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1512" class="blob-line-num js-line-number" data-line-number="1512"></td>
        <td id="LC1512" class="blob-line-code js-file-line">    <span class="n">ZNGoodJetsEWK_Zexc</span><span class="o">-&gt;</span><span class="n">GetXaxis</span><span class="p">()</span><span class="o">-&gt;</span><span class="n">SetBinLabel</span><span class="p">(</span><span class="mi">11</span><span class="p">,</span><span class="s">&quot;= 10&quot;</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1513" class="blob-line-num js-line-number" data-line-number="1513"></td>
        <td id="LC1513" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1514" class="blob-line-num js-line-number" data-line-number="1514"></td>
        <td id="LC1514" class="blob-line-code js-file-line">    <span class="c1">// met properties</span></td>
      </tr>
      <tr>
        <td id="L1515" class="blob-line-num js-line-number" data-line-number="1515"></td>
        <td id="LC1515" class="blob-line-code js-file-line">    <span class="n">METEWKmjj_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;M_{jj} #geq 1 TeV: MET (N_{jets} #geq 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">500</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1516" class="blob-line-num js-line-number" data-line-number="1516"></td>
        <td id="LC1516" class="blob-line-code js-file-line">    <span class="n">METEWKmjj_Zinc3jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METEWKmjj_Zinc3jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;M_{jj} #geq 1 TeV: MET (N_{jets} #geq 3)&quot;</span><span class="p">,</span>  <span class="s">&quot;MET [GeV]&quot;</span><span class="p">,</span>      <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">500</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1517" class="blob-line-num js-line-number" data-line-number="1517"></td>
        <td id="LC1517" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1518" class="blob-line-num js-line-number" data-line-number="1518"></td>
        <td id="LC1518" class="blob-line-code js-file-line">    <span class="n">METphiEWKmjj_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;METphiEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;M_{jj} #geq 1 TeV: MET #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>  <span class="s">&quot;#phi(MET)&quot;</span><span class="p">,</span>      <span class="mi">100</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span> <span class="p">,</span><span class="n">PI</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1519" class="blob-line-num js-line-number" data-line-number="1519"></td>
        <td id="LC1519" class="blob-line-code js-file-line">    <span class="c1">///TH1D *METphiEWKmjj_Zinc3jet                      = newTH1D(&quot;METphiEWKmjj_Zinc3jet&quot;,                   &quot;M_{jj} #geq 1 TeV: MET #phi (N_{jets} #geq 3)&quot;,  &quot;#phi(MET)&quot;,      100,-PI ,PI );</span></td>
      </tr>
      <tr>
        <td id="L1520" class="blob-line-num js-line-number" data-line-number="1520"></td>
        <td id="LC1520" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1521" class="blob-line-num js-line-number" data-line-number="1521"></td>
        <td id="LC1521" class="blob-line-code js-file-line">    <span class="n">MTEWKmjj_Zinc2jet</span>                      <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;MTEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>                   <span class="s">&quot;M_{jj} #geq 1 TeV: MT (N_{jets} #geq 2)&quot;</span><span class="p">,</span>    <span class="s">&quot;MT [GeV]&quot;</span><span class="p">,</span>    <span class="mi">200</span><span class="p">,</span><span class="mf">0.</span><span class="p">,</span><span class="mi">400</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1522" class="blob-line-num js-line-number" data-line-number="1522"></td>
        <td id="LC1522" class="blob-line-code js-file-line">    <span class="c1">//TH1D *MTEWKmjj_Zinc3jet                      = newTH1D(&quot;MTEWKmjj_Zinc3jet&quot;,                   &quot;M_{jj} #geq 1 TeV: MT (N_{jets} #geq 3)&quot;,    &quot;MT [GeV]&quot;,    200,0.,400 );</span></td>
      </tr>
      <tr>
        <td id="L1523" class="blob-line-num js-line-number" data-line-number="1523"></td>
        <td id="LC1523" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1524" class="blob-line-num js-line-number" data-line-number="1524"></td>
        <td id="LC1524" class="blob-line-code js-file-line">    <span class="c1">// jet hisotgrams</span></td>
      </tr>
      <tr>
        <td id="L1525" class="blob-line-num js-line-number" data-line-number="1525"></td>
        <td id="LC1525" class="blob-line-code js-file-line">    <span class="n">FirstJetPtEWKmjj_Zinc2jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPtEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>              <span class="s">&quot;M_{jj} #geq 1 TeV: 1st jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1526" class="blob-line-num js-line-number" data-line-number="1526"></td>
        <td id="LC1526" class="blob-line-code js-file-line">    <span class="n">SecondJetPtEWKmjj_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPtEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;M_{jj} #geq 1 TeV: 2nd jet p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1527" class="blob-line-num js-line-number" data-line-number="1527"></td>
        <td id="LC1527" class="blob-line-code js-file-line">    <span class="n">ThirdJetPtEWKmjj_Zinc3jet</span>                 <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetPtEWKmjj_Zinc3jet&quot;</span><span class="p">,</span>              <span class="s">&quot;M_{jj} #geq 1 TeV: 3rd jet p_{T} (N_{jets} #geq 3)&quot;</span><span class="p">,</span>             <span class="s">&quot;p_{T}(j_{3}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">nJetPtEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetPtEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1528" class="blob-line-num js-line-number" data-line-number="1528"></td>
        <td id="LC1528" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1529" class="blob-line-num js-line-number" data-line-number="1529"></td>
        <td id="LC1529" class="blob-line-code js-file-line">    <span class="n">FirstJetEtaEWKmjj_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetEtaEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;M_{jj} #geq 1 TeV: 1st jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1530" class="blob-line-num js-line-number" data-line-number="1530"></td>
        <td id="LC1530" class="blob-line-code js-file-line">    <span class="n">SecondJetEtaEWKmjj_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetEtaEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;M_{jj} #geq 1 TeV: 2nd jet #eta (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#eta(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">24</span><span class="p">,</span><span class="o">-</span><span class="mf">4.8</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1531" class="blob-line-num js-line-number" data-line-number="1531"></td>
        <td id="LC1531" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1532" class="blob-line-num js-line-number" data-line-number="1532"></td>
        <td id="LC1532" class="blob-line-code js-file-line">    <span class="n">FirstJetPhiEWKmjj_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;FirstJetPhiEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;M_{jj} #geq 1 TeV: 1st jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{1})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1533" class="blob-line-num js-line-number" data-line-number="1533"></td>
        <td id="LC1533" class="blob-line-code js-file-line">    <span class="n">SecondJetPhiEWKmjj_Zinc2jet</span>               <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SecondJetPhiEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>            <span class="s">&quot;M_{jj} #geq 1 TeV: 2nd jet #phi (N_{jets} #geq 2)&quot;</span><span class="p">,</span>              <span class="s">&quot;#phi(j_{2})&quot;</span><span class="p">,</span>  <span class="mi">30</span><span class="p">,</span><span class="o">-</span><span class="n">PI</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1534" class="blob-line-num js-line-number" data-line-number="1534"></td>
        <td id="LC1534" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1535" class="blob-line-num js-line-number" data-line-number="1535"></td>
        <td id="LC1535" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1536" class="blob-line-num js-line-number" data-line-number="1536"></td>
        <td id="LC1536" class="blob-line-code js-file-line">    <span class="n">SumEtaJetsEWKmjj_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SumEtaJetsEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;M_{jj} #geq 1 TeV: sum of #eta of j1,j2 jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1537" class="blob-line-num js-line-number" data-line-number="1537"></td>
        <td id="LC1537" class="blob-line-code js-file-line">    <span class="n">SumEtaJetsEWKmjj_Zinc3jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SumEtaJetsEWKmjj_Zinc3jet&quot;</span><span class="p">,</span>          <span class="s">&quot;M_{jj} #geq 1 TeV: sum of #eta of j1,j2 jets (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                                       <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1538" class="blob-line-num js-line-number" data-line-number="1538"></td>
        <td id="LC1538" class="blob-line-code js-file-line">    <span class="n">genSumEtaJetsEWKmjj_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSumEtaJetsEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;M_{jj} #geq 1 TeV: gen sum of #eta of j1,j2 jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jSEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">8</span><span class="p">,</span> <span class="mi">8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1539" class="blob-line-num js-line-number" data-line-number="1539"></td>
        <td id="LC1539" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1540" class="blob-line-num js-line-number" data-line-number="1540"></td>
        <td id="LC1540" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1541" class="blob-line-num js-line-number" data-line-number="1541"></td>
        <td id="LC1541" class="blob-line-code js-file-line">    <span class="n">dEtaJetsEWKmjj_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaJetsEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;M_{jj} #geq 1 TeV: #Delta#eta btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1542" class="blob-line-num js-line-number" data-line-number="1542"></td>
        <td id="LC1542" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1543" class="blob-line-num js-line-number" data-line-number="1543"></td>
        <td id="LC1543" class="blob-line-code js-file-line">    <span class="n">gendEtaJetsEWKmjj_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaJetsEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;M_{jj} #geq 1 TeV: gen #Delta#eta btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jdEta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">10</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1544" class="blob-line-num js-line-number" data-line-number="1544"></td>
        <td id="LC1544" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1545" class="blob-line-num js-line-number" data-line-number="1545"></td>
        <td id="LC1545" class="blob-line-code js-file-line">    <span class="n">TwoJetsPtDiffEWKmjj_Zinc2jet</span>        <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;TwoJetsPtDiffEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>     <span class="s">&quot;M_{jj} #geq 1 TeV: pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                             <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">500</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1546" class="blob-line-num js-line-number" data-line-number="1546"></td>
        <td id="LC1546" class="blob-line-code js-file-line">    <span class="n">genTwoJetsPtDiffEWKmjj_Zinc2jet</span>     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genTwoJetsPtDiffEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>  <span class="s">&quot;M_{jj} #geq 1 TeV: gen pT diff of the two highest jet (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                         <span class="s">&quot;#Delta pT(j_{1}j_{2}) [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1000</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1547" class="blob-line-num js-line-number" data-line-number="1547"></td>
        <td id="LC1547" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1548" class="blob-line-num js-line-number" data-line-number="1548"></td>
        <td id="LC1548" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1549" class="blob-line-num js-line-number" data-line-number="1549"></td>
        <td id="LC1549" class="blob-line-code js-file-line">    <span class="n">ptBalEWKmjj_Zinc2jet</span>                <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ptBalEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>             <span class="s">&quot;M_{jj} #geq 1 TeV: Vectorial pT sum: Z_{pT} + Jets_{pT} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                       <span class="s">&quot;#Sigma pT [GeV]&quot;</span><span class="p">,</span>      <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">500</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1550" class="blob-line-num js-line-number" data-line-number="1550"></td>
        <td id="LC1550" class="blob-line-code js-file-line">    <span class="n">SpTJetsEWKmjj_Zinc2jet</span>              <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;SpTJetsEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>           <span class="s">&quot;M_{jj} #geq 1 TeV: #Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1551" class="blob-line-num js-line-number" data-line-number="1551"></td>
        <td id="LC1551" class="blob-line-code js-file-line">    <span class="n">genSpTJetsEWKmjj_Zinc2jet</span>           <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genSpTJetsEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>        <span class="s">&quot;M_{jj} #geq 1 TeV: gen #Delta_{pT}^{rel} jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                            <span class="n">jSpt</span><span class="p">,</span>   <span class="mi">50</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1552" class="blob-line-num js-line-number" data-line-number="1552"></td>
        <td id="LC1552" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1553" class="blob-line-num js-line-number" data-line-number="1553"></td>
        <td id="LC1553" class="blob-line-code js-file-line">    <span class="n">dPhiJetsEWKmjj_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dPhiJetsEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;M_{jj} #geq 1 TeV: #Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">100</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1554" class="blob-line-num js-line-number" data-line-number="1554"></td>
        <td id="LC1554" class="blob-line-code js-file-line">    <span class="n">gendPhiJetsEWKmjj_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendPhiJetsEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;M_{jj} #geq 1 TeV: gen #Delta#phi btwn jets (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">jdPhi</span><span class="p">,</span>           <span class="mi">100</span><span class="p">,</span>  <span class="mi">0</span><span class="p">,</span> <span class="n">PI</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1555" class="blob-line-num js-line-number" data-line-number="1555"></td>
        <td id="LC1555" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1556" class="blob-line-num js-line-number" data-line-number="1556"></td>
        <td id="LC1556" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1557" class="blob-line-num js-line-number" data-line-number="1557"></td>
        <td id="LC1557" class="blob-line-code js-file-line">    <span class="n">JetsHTEWKmjj_Zinc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHTEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;M_{jj} #geq 1 TeV: Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHTEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1558" class="blob-line-num js-line-number" data-line-number="1558"></td>
        <td id="LC1558" class="blob-line-code js-file-line">    <span class="n">genJetsHTEWKmjj_Zinc2jet</span>                  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsHTEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>               <span class="s">&quot;M_{jj} #geq 1 TeV: Scalar sum jets p_{T} (N_{jets} #geq 2)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetHTEWK_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWK_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1559" class="blob-line-num js-line-number" data-line-number="1559"></td>
        <td id="LC1559" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1560" class="blob-line-num js-line-number" data-line-number="1560"></td>
        <td id="LC1560" class="blob-line-code js-file-line">    <span class="n">JetsHTEWKmjjAdd_Zinc2jet</span>                     <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsHTEWKmjjAdd_Zinc2jet&quot;</span><span class="p">,</span>                  <span class="s">&quot;M_{jj} #geq 1 TeV: Scalar sum jets p_{T} , 15 GeV cut on third)&quot;</span><span class="p">,</span>     <span class="n">HT</span><span class="p">,</span>     <span class="n">nJetPtEWKbtw_Zinc2jet</span><span class="p">,</span> <span class="n">jetHTEWKbtw_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1561" class="blob-line-num js-line-number" data-line-number="1561"></td>
        <td id="LC1561" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1562" class="blob-line-num js-line-number" data-line-number="1562"></td>
        <td id="LC1562" class="blob-line-code js-file-line">    <span class="n">JetsMassEWKmjj_Zinc2jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;JetsMassEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>          <span class="s">&quot;M_{jj} #geq 1 TeV: 2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                       <span class="n">Mjj</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">1000</span><span class="p">,</span> <span class="mi">2620</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1563" class="blob-line-num js-line-number" data-line-number="1563"></td>
        <td id="LC1563" class="blob-line-code js-file-line">    <span class="n">genJetsMassEWKmjj_Zinc2jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;genJetsMassEWKmjj_Zinc2jet&quot;</span><span class="p">,</span>       <span class="s">&quot;M_{jj} #geq 1 TeV: gen 2Jets Invariant Mass (N_{jets} #geq 2)&quot;</span><span class="p">,</span>                                   <span class="n">Mjj</span><span class="p">,</span> <span class="mi">50</span><span class="p">,</span> <span class="mi">1000</span><span class="p">,</span> <span class="mi">2620</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1564" class="blob-line-num js-line-number" data-line-number="1564"></td>
        <td id="LC1564" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1565" class="blob-line-num js-line-number" data-line-number="1565"></td>
        <td id="LC1565" class="blob-line-code js-file-line">    <span class="c1">//// third jet properties</span></td>
      </tr>
      <tr>
        <td id="L1566" class="blob-line-num js-line-number" data-line-number="1566"></td>
        <td id="LC1566" class="blob-line-code js-file-line">    <span class="n">ThirdJetEtaEWKmjj_Zinc3jet</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;ThirdJetEtaEWKmjj_Zinc3jet&quot;</span><span class="p">,</span>             <span class="s">&quot;M_{jj} #geq 1 TeV: Third jet #eta in dijet frame (N_{jets} #geq 3)&quot;</span><span class="p">,</span>                                       <span class="n">j3Eta</span><span class="p">,</span>           <span class="mi">50</span><span class="p">,</span> <span class="o">-</span><span class="mi">5</span><span class="p">,</span> <span class="mi">5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1567" class="blob-line-num js-line-number" data-line-number="1567"></td>
        <td id="LC1567" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1568" class="blob-line-num js-line-number" data-line-number="1568"></td>
        <td id="LC1568" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1569" class="blob-line-num js-line-number" data-line-number="1569"></td>
        <td id="LC1569" class="blob-line-code js-file-line">    <span class="n">partonsN</span>          <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;partonsN&quot;</span><span class="p">,</span><span class="s">&quot;Number of ME partons &quot;</span><span class="p">,</span> <span class="s">&quot;N_{partons}&quot;</span><span class="p">,</span> <span class="mi">16</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">15.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1570" class="blob-line-num js-line-number" data-line-number="1570"></td>
        <td id="LC1570" class="blob-line-code js-file-line">    <span class="n">partonsNWeighted</span>  <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;partonsNWeighted&quot;</span><span class="p">,</span><span class="s">&quot;Number of ME partons: weighted &quot;</span><span class="p">,</span> <span class="s">&quot;N_{partons}&quot;</span><span class="p">,</span> <span class="mi">16</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">15.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1571" class="blob-line-num js-line-number" data-line-number="1571"></td>
        <td id="LC1571" class="blob-line-code js-file-line">    <span class="n">partonsNAfterGenCut</span>         <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;partonsNAfterGenCut&quot;</span><span class="p">,</span><span class="s">&quot;Number of ME partons passing the gen cut&quot;</span><span class="p">,</span> <span class="s">&quot;N_{partons}&quot;</span><span class="p">,</span> <span class="mi">16</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">15.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1572" class="blob-line-num js-line-number" data-line-number="1572"></td>
        <td id="LC1572" class="blob-line-code js-file-line">    <span class="n">partonsNAfterGenCutWeighted</span> <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;partonsNAfterGenCutWeighted&quot;</span><span class="p">,</span><span class="s">&quot;Number of ME partons passing the gen cut:weighted&quot;</span><span class="p">,</span> <span class="s">&quot;N_{partons}&quot;</span><span class="p">,</span> <span class="mi">16</span><span class="p">,</span> <span class="o">-</span><span class="mf">0.5</span><span class="p">,</span> <span class="mf">15.5</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1573" class="blob-line-num js-line-number" data-line-number="1573"></td>
        <td id="LC1573" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1574" class="blob-line-num js-line-number" data-line-number="1574"></td>
        <td id="LC1574" class="blob-line-code js-file-line">    <span class="c1">// vector boson and single jet</span></td>
      </tr>
      <tr>
        <td id="L1575" class="blob-line-num js-line-number" data-line-number="1575"></td>
        <td id="LC1575" class="blob-line-code js-file-line">    <span class="n">dEtaBosonJet_Zexc1jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaBosonJet_Zexc1&quot;</span><span class="p">,</span>             <span class="s">&quot;#Delta#eta btwn leading jet and V (N_{jets} #eq )) &quot;</span><span class="p">,</span>                                                   <span class="n">lJetdEta</span><span class="p">,</span>           <span class="mi">72</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1576" class="blob-line-num js-line-number" data-line-number="1576"></td>
        <td id="LC1576" class="blob-line-code js-file-line">    <span class="n">dEtaBosonJet_Zinc1jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;dEtaBosonJet_Zinc1&quot;</span><span class="p">,</span>             <span class="s">&quot;#Delta#eta btwn leading jet and V (N_{jets} #geq )) &quot;</span><span class="p">,</span>                                                   <span class="n">lJetdEta</span><span class="p">,</span>           <span class="mi">72</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1577" class="blob-line-num js-line-number" data-line-number="1577"></td>
        <td id="LC1577" class="blob-line-code js-file-line">    <span class="n">gendEtaBosonJet_Zexc1jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaBosonJet_Zexc1&quot;</span><span class="p">,</span>             <span class="s">&quot;gen #Delta#eta btwn leading jet and V (N_{jets} #eq )) &quot;</span><span class="p">,</span>                                                   <span class="n">lJetdEta</span><span class="p">,</span>           <span class="mi">72</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1578" class="blob-line-num js-line-number" data-line-number="1578"></td>
        <td id="LC1578" class="blob-line-code js-file-line">    <span class="n">gendEtaBosonJet_Zinc1jet</span>             <span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="s">&quot;gendEtaBosonJet_Zinc1&quot;</span><span class="p">,</span>             <span class="s">&quot;gen #Delta#eta btwn leading jet and V (N_{jets} #geq )) &quot;</span><span class="p">,</span>                                                   <span class="n">lJetdEta</span><span class="p">,</span>           <span class="mi">72</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mf">4.8</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1579" class="blob-line-num js-line-number" data-line-number="1579"></td>
        <td id="LC1579" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1580" class="blob-line-num js-line-number" data-line-number="1580"></td>
        <td id="LC1580" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1581" class="blob-line-num js-line-number" data-line-number="1581"></td>
        <td id="LC1581" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1582" class="blob-line-num js-line-number" data-line-number="1582"></td>
        <td id="LC1582" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1583" class="blob-line-num js-line-number" data-line-number="1583"></td>
        <td id="LC1583" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1584" class="blob-line-num js-line-number" data-line-number="1584"></td>
        <td id="LC1584" class="blob-line-code js-file-line">    <span class="c1">//--- RooUnfoldResponses ---</span></td>
      </tr>
      <tr>
        <td id="L1585" class="blob-line-num js-line-number" data-line-number="1585"></td>
        <td id="LC1585" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1586" class="blob-line-num js-line-number" data-line-number="1586"></td>
        <td id="LC1586" class="blob-line-code js-file-line">    <span class="n">responseZNGoodJetsExc</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ZNGoodJets_Zexc</span><span class="p">,</span>                   <span class="n">genZNGoodJets_Zexc</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1587" class="blob-line-num js-line-number" data-line-number="1587"></td>
        <td id="LC1587" class="blob-line-code js-file-line">    <span class="n">responseZMass</span>                       <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ZMass_Zinc0jet</span><span class="p">,</span>                    <span class="n">genZMass_Zinc0jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1588" class="blob-line-num js-line-number" data-line-number="1588"></td>
        <td id="LC1588" class="blob-line-code js-file-line">    <span class="n">responseTwoJetsPtDiffExc</span>            <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">TwoJetsPtDiff_Zexc2jet</span><span class="p">,</span>            <span class="n">genTwoJetsPtDiff_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1589" class="blob-line-num js-line-number" data-line-number="1589"></td>
        <td id="LC1589" class="blob-line-code js-file-line">    <span class="n">responseTwoJetsPtDiffInc</span>            <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">TwoJetsPtDiff_Zinc2jet</span><span class="p">,</span>            <span class="n">genTwoJetsPtDiff_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1590" class="blob-line-num js-line-number" data-line-number="1590"></td>
        <td id="LC1590" class="blob-line-code js-file-line">    <span class="n">responseBestTwoJetsPtDiffInc</span>        <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestTwoJetsPtDiff_Zinc2jet</span><span class="p">,</span>        <span class="n">genBestTwoJetsPtDiff_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1591" class="blob-line-num js-line-number" data-line-number="1591"></td>
        <td id="LC1591" class="blob-line-code js-file-line">    <span class="n">responseTwoJetsPtDiffLowPtExc</span>       <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">TwoJetsPtDiff_LowPt_Zexc2jet</span><span class="p">,</span>      <span class="n">genTwoJetsPtDiff_LowPt_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1592" class="blob-line-num js-line-number" data-line-number="1592"></td>
        <td id="LC1592" class="blob-line-code js-file-line">    <span class="n">responseTwoJetsPtDiffLowPtInc</span>       <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">TwoJetsPtDiff_LowPt_Zinc2jet</span><span class="p">,</span>      <span class="n">genTwoJetsPtDiff_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1593" class="blob-line-num js-line-number" data-line-number="1593"></td>
        <td id="LC1593" class="blob-line-code js-file-line">    <span class="n">responseBestTwoJetsPtDiffLowPtInc</span>   <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestTwoJetsPtDiff_LowPt_Zinc2jet</span><span class="p">,</span>  <span class="n">genBestTwoJetsPtDiff_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1594" class="blob-line-num js-line-number" data-line-number="1594"></td>
        <td id="LC1594" class="blob-line-code js-file-line">    <span class="n">responseJetsMassExc</span>                 <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsMass_Zexc2jet</span><span class="p">,</span>                 <span class="n">genJetsMass_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1595" class="blob-line-num js-line-number" data-line-number="1595"></td>
        <td id="LC1595" class="blob-line-code js-file-line">    <span class="n">responseJetsMassInc</span>                 <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsMass_Zinc2jet</span><span class="p">,</span>                 <span class="n">genJetsMass_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1596" class="blob-line-num js-line-number" data-line-number="1596"></td>
        <td id="LC1596" class="blob-line-code js-file-line">    <span class="n">responseBestJetsMassInc</span>             <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestJetsMass_Zinc2jet</span><span class="p">,</span>             <span class="n">genBestJetsMass_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1597" class="blob-line-num js-line-number" data-line-number="1597"></td>
        <td id="LC1597" class="blob-line-code js-file-line">    <span class="n">responseJetsMassLowPtExc</span>            <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsMass_LowPt_Zexc2jet</span><span class="p">,</span>           <span class="n">genJetsMass_LowPt_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1598" class="blob-line-num js-line-number" data-line-number="1598"></td>
        <td id="LC1598" class="blob-line-code js-file-line">    <span class="n">responseJetsMassLowPtInc</span>            <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsMass_LowPt_Zinc2jet</span><span class="p">,</span>           <span class="n">genJetsMass_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1599" class="blob-line-num js-line-number" data-line-number="1599"></td>
        <td id="LC1599" class="blob-line-code js-file-line">    <span class="n">responseBestJetsMassLowPtInc</span>        <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestJetsMass_LowPt_Zinc2jet</span><span class="p">,</span>       <span class="n">genBestJetsMass_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1600" class="blob-line-num js-line-number" data-line-number="1600"></td>
        <td id="LC1600" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1601" class="blob-line-num js-line-number" data-line-number="1601"></td>
        <td id="LC1601" class="blob-line-code js-file-line">    <span class="n">responseFirstJetPt</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstJetPt_Zinc1jet</span><span class="p">,</span>               <span class="n">genFirstJetPt_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1602" class="blob-line-num js-line-number" data-line-number="1602"></td>
        <td id="LC1602" class="blob-line-code js-file-line">    <span class="n">responseFirstJetPt_1</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstJetPt_1_Zinc1jet</span><span class="p">,</span>             <span class="n">genFirstJetPt_1_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1603" class="blob-line-num js-line-number" data-line-number="1603"></td>
        <td id="LC1603" class="blob-line-code js-file-line">    <span class="n">responseFirstJetPt_2</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstJetPt_2_Zinc1jet</span><span class="p">,</span>             <span class="n">genFirstJetPt_2_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1604" class="blob-line-num js-line-number" data-line-number="1604"></td>
        <td id="LC1604" class="blob-line-code js-file-line">    <span class="n">responseFirstJetPt_3</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstJetPt_3_Zinc1jet</span><span class="p">,</span>             <span class="n">genFirstJetPt_3_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1605" class="blob-line-num js-line-number" data-line-number="1605"></td>
        <td id="LC1605" class="blob-line-code js-file-line">    <span class="n">responseFirstJetPt_4</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstJetPt_4_Zinc1jet</span><span class="p">,</span>             <span class="n">genFirstJetPt_4_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1606" class="blob-line-num js-line-number" data-line-number="1606"></td>
        <td id="LC1606" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1607" class="blob-line-num js-line-number" data-line-number="1607"></td>
        <td id="LC1607" class="blob-line-code js-file-line">    <span class="n">responseSecondJetPt</span>                 <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondJetPt_Zinc2jet</span><span class="p">,</span>              <span class="n">genSecondJetPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1608" class="blob-line-num js-line-number" data-line-number="1608"></td>
        <td id="LC1608" class="blob-line-code js-file-line">    <span class="n">responseSecondJetPt_1</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondJetPt_1_Zinc2jet</span><span class="p">,</span>            <span class="n">genSecondJetPt_1_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1609" class="blob-line-num js-line-number" data-line-number="1609"></td>
        <td id="LC1609" class="blob-line-code js-file-line">    <span class="n">responseSecondJetPt_2</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondJetPt_2_Zinc2jet</span><span class="p">,</span>            <span class="n">genSecondJetPt_2_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1610" class="blob-line-num js-line-number" data-line-number="1610"></td>
        <td id="LC1610" class="blob-line-code js-file-line">    <span class="n">responseSecondJetPt_3</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondJetPt_3_Zinc2jet</span><span class="p">,</span>            <span class="n">genSecondJetPt_3_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1611" class="blob-line-num js-line-number" data-line-number="1611"></td>
        <td id="LC1611" class="blob-line-code js-file-line">    <span class="n">responseSecondJetPt_4</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondJetPt_4_Zinc2jet</span><span class="p">,</span>            <span class="n">genSecondJetPt_4_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1612" class="blob-line-num js-line-number" data-line-number="1612"></td>
        <td id="LC1612" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1613" class="blob-line-num js-line-number" data-line-number="1613"></td>
        <td id="LC1613" class="blob-line-code js-file-line">    <span class="n">responseThirdJetPt</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdJetPt_Zinc3jet</span><span class="p">,</span>              <span class="n">genThirdJetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1614" class="blob-line-num js-line-number" data-line-number="1614"></td>
        <td id="LC1614" class="blob-line-code js-file-line">    <span class="n">responseThirdJetPt_1</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdJetPt_1_Zinc3jet</span><span class="p">,</span>            <span class="n">genThirdJetPt_1_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1615" class="blob-line-num js-line-number" data-line-number="1615"></td>
        <td id="LC1615" class="blob-line-code js-file-line">    <span class="n">responseThirdJetPt_2</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdJetPt_2_Zinc3jet</span><span class="p">,</span>            <span class="n">genThirdJetPt_2_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1616" class="blob-line-num js-line-number" data-line-number="1616"></td>
        <td id="LC1616" class="blob-line-code js-file-line">    <span class="n">responseThirdJetPt_3</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdJetPt_3_Zinc3jet</span><span class="p">,</span>            <span class="n">genThirdJetPt_3_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1617" class="blob-line-num js-line-number" data-line-number="1617"></td>
        <td id="LC1617" class="blob-line-code js-file-line">    <span class="n">responseThirdJetPt_4</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdJetPt_4_Zinc3jet</span><span class="p">,</span>            <span class="n">genThirdJetPt_4_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1618" class="blob-line-num js-line-number" data-line-number="1618"></td>
        <td id="LC1618" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1619" class="blob-line-num js-line-number" data-line-number="1619"></td>
        <td id="LC1619" class="blob-line-code js-file-line">    <span class="n">responseFirstJetEta</span>                 <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstJetEta_Zinc1jet</span><span class="p">,</span>              <span class="n">genFirstJetEta_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1620" class="blob-line-num js-line-number" data-line-number="1620"></td>
        <td id="LC1620" class="blob-line-code js-file-line">    <span class="n">responseFirstJetPtEta</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstJetPtEta_Zinc1jet</span><span class="p">,</span>            <span class="n">genFirstJetPtEta_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1621" class="blob-line-num js-line-number" data-line-number="1621"></td>
        <td id="LC1621" class="blob-line-code js-file-line">    <span class="n">responseSecondJetEta</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondJetEta_Zinc2jet</span><span class="p">,</span>             <span class="n">genSecondJetEta_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1622" class="blob-line-num js-line-number" data-line-number="1622"></td>
        <td id="LC1622" class="blob-line-code js-file-line">    <span class="n">responseSecondJetPtEta</span>              <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondJetPtEta_Zinc2jet</span><span class="p">,</span>           <span class="n">genSecondJetPtEta_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1623" class="blob-line-num js-line-number" data-line-number="1623"></td>
        <td id="LC1623" class="blob-line-code js-file-line">    <span class="n">responseThirdJetEta</span>                 <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdJetEta_Zinc3jet</span><span class="p">,</span>              <span class="n">genThirdJetEta_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1624" class="blob-line-num js-line-number" data-line-number="1624"></td>
        <td id="LC1624" class="blob-line-code js-file-line">    <span class="n">responseThirdJetPtEta</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdJetPtEta_Zinc3jet</span><span class="p">,</span>            <span class="n">genThirdJetPtEta_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1625" class="blob-line-num js-line-number" data-line-number="1625"></td>
        <td id="LC1625" class="blob-line-code js-file-line">    <span class="n">responseFourthJetPt</span>                 <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FourthJetPt_Zinc4jet</span><span class="p">,</span>              <span class="n">genFourthJetPt_Zinc4jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1626" class="blob-line-num js-line-number" data-line-number="1626"></td>
        <td id="LC1626" class="blob-line-code js-file-line">    <span class="n">responseFourthJetEta</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FourthJetEta_Zinc4jet</span><span class="p">,</span>             <span class="n">genFourthJetEta_Zinc4jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1627" class="blob-line-num js-line-number" data-line-number="1627"></td>
        <td id="LC1627" class="blob-line-code js-file-line">    <span class="n">responseFourthJetPtEta</span>              <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FourthJetPtEta_Zinc4jet</span><span class="p">,</span>           <span class="n">genFourthJetPtEta_Zinc4jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1628" class="blob-line-num js-line-number" data-line-number="1628"></td>
        <td id="LC1628" class="blob-line-code js-file-line">    <span class="n">responseFifthJetPt</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FifthJetPt_Zinc5jet</span><span class="p">,</span>               <span class="n">genFifthJetPt_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1629" class="blob-line-num js-line-number" data-line-number="1629"></td>
        <td id="LC1629" class="blob-line-code js-file-line">    <span class="n">responseFifthJetEta</span>                 <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FifthJetEta_Zinc5jet</span><span class="p">,</span>              <span class="n">genFifthJetEta_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1630" class="blob-line-num js-line-number" data-line-number="1630"></td>
        <td id="LC1630" class="blob-line-code js-file-line">    <span class="n">responseFifthJetPtEta</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FifthJetPtEta_Zinc5jet</span><span class="p">,</span>            <span class="n">genFifthJetPtEta_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1631" class="blob-line-num js-line-number" data-line-number="1631"></td>
        <td id="LC1631" class="blob-line-code js-file-line">    <span class="n">responseSixthJetPt</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SixthJetPt_Zinc6jet</span><span class="p">,</span>               <span class="n">genSixthJetPt_Zinc6jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1632" class="blob-line-num js-line-number" data-line-number="1632"></td>
        <td id="LC1632" class="blob-line-code js-file-line">    <span class="n">responseSixthJetEta</span>                 <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SixthJetEta_Zinc6jet</span><span class="p">,</span>              <span class="n">genSixthJetEta_Zinc6jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1633" class="blob-line-num js-line-number" data-line-number="1633"></td>
        <td id="LC1633" class="blob-line-code js-file-line">    <span class="n">responseSixthJetPtEta</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SixthJetPtEta_Zinc6jet</span><span class="p">,</span>            <span class="n">genSixthJetPtEta_Zinc6jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1634" class="blob-line-num js-line-number" data-line-number="1634"></td>
        <td id="LC1634" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1635" class="blob-line-num js-line-number" data-line-number="1635"></td>
        <td id="LC1635" class="blob-line-code js-file-line">    <span class="n">responseJetsHt1Jet</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_Zinc1jet</span><span class="p">,</span>                   <span class="n">genJetsHT_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1636" class="blob-line-num js-line-number" data-line-number="1636"></td>
        <td id="LC1636" class="blob-line-code js-file-line">    <span class="n">responseJetsHt1Jet_1</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_1_Zinc1jet</span><span class="p">,</span>                 <span class="n">genJetsHT_1_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1637" class="blob-line-num js-line-number" data-line-number="1637"></td>
        <td id="LC1637" class="blob-line-code js-file-line">    <span class="n">responseJetsHt1Jet_2</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_2_Zinc1jet</span><span class="p">,</span>                 <span class="n">genJetsHT_2_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1638" class="blob-line-num js-line-number" data-line-number="1638"></td>
        <td id="LC1638" class="blob-line-code js-file-line">    <span class="n">responseJetsHt1Jet_3</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_3_Zinc1jet</span><span class="p">,</span>                 <span class="n">genJetsHT_3_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1639" class="blob-line-num js-line-number" data-line-number="1639"></td>
        <td id="LC1639" class="blob-line-code js-file-line">    <span class="n">responseJetsHt1Jet_4</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_4_Zinc1jet</span><span class="p">,</span>                 <span class="n">genJetsHT_4_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1640" class="blob-line-num js-line-number" data-line-number="1640"></td>
        <td id="LC1640" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1641" class="blob-line-num js-line-number" data-line-number="1641"></td>
        <td id="LC1641" class="blob-line-code js-file-line">    <span class="n">responseJetsHt2Jet</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_Zinc2jet</span><span class="p">,</span>                   <span class="n">genJetsHT_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1642" class="blob-line-num js-line-number" data-line-number="1642"></td>
        <td id="LC1642" class="blob-line-code js-file-line">    <span class="n">responseJetsHt2Jet_1</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_1_Zinc2jet</span><span class="p">,</span>                 <span class="n">genJetsHT_1_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1643" class="blob-line-num js-line-number" data-line-number="1643"></td>
        <td id="LC1643" class="blob-line-code js-file-line">    <span class="n">responseJetsHt2Jet_2</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_2_Zinc2jet</span><span class="p">,</span>                 <span class="n">genJetsHT_2_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1644" class="blob-line-num js-line-number" data-line-number="1644"></td>
        <td id="LC1644" class="blob-line-code js-file-line">    <span class="n">responseJetsHt2Jet_3</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_3_Zinc2jet</span><span class="p">,</span>                 <span class="n">genJetsHT_3_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1645" class="blob-line-num js-line-number" data-line-number="1645"></td>
        <td id="LC1645" class="blob-line-code js-file-line">    <span class="n">responseJetsHt2Jet_4</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_4_Zinc2jet</span><span class="p">,</span>                 <span class="n">genJetsHT_4_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1646" class="blob-line-num js-line-number" data-line-number="1646"></td>
        <td id="LC1646" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1647" class="blob-line-num js-line-number" data-line-number="1647"></td>
        <td id="LC1647" class="blob-line-code js-file-line">    <span class="n">responseJetsHt3Jet</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_Zinc3jet</span><span class="p">,</span>                   <span class="n">genJetsHT_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1648" class="blob-line-num js-line-number" data-line-number="1648"></td>
        <td id="LC1648" class="blob-line-code js-file-line">    <span class="n">responseJetsHt3Jet_1</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_1_Zinc3jet</span><span class="p">,</span>                 <span class="n">genJetsHT_1_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1649" class="blob-line-num js-line-number" data-line-number="1649"></td>
        <td id="LC1649" class="blob-line-code js-file-line">    <span class="n">responseJetsHt3Jet_2</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_2_Zinc3jet</span><span class="p">,</span>                 <span class="n">genJetsHT_2_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1650" class="blob-line-num js-line-number" data-line-number="1650"></td>
        <td id="LC1650" class="blob-line-code js-file-line">    <span class="n">responseJetsHt3Jet_3</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_3_Zinc3jet</span><span class="p">,</span>                 <span class="n">genJetsHT_3_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1651" class="blob-line-num js-line-number" data-line-number="1651"></td>
        <td id="LC1651" class="blob-line-code js-file-line">    <span class="n">responseJetsHt3Jet_4</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_4_Zinc3jet</span><span class="p">,</span>                 <span class="n">genJetsHT_4_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1652" class="blob-line-num js-line-number" data-line-number="1652"></td>
        <td id="LC1652" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1653" class="blob-line-num js-line-number" data-line-number="1653"></td>
        <td id="LC1653" class="blob-line-code js-file-line">    <span class="n">responseJetsHt4Jet</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_Zinc4jet</span><span class="p">,</span>                   <span class="n">genJetsHT_Zinc4jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1654" class="blob-line-num js-line-number" data-line-number="1654"></td>
        <td id="LC1654" class="blob-line-code js-file-line">    <span class="n">responseJetsHt5Jet</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_Zinc5jet</span><span class="p">,</span>                   <span class="n">genJetsHT_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1655" class="blob-line-num js-line-number" data-line-number="1655"></td>
        <td id="LC1655" class="blob-line-code js-file-line">    <span class="n">responseJetsHt6Jet</span>                  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">JetsHT_Zinc6jet</span><span class="p">,</span>                   <span class="n">genJetsHT_Zinc6jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1656" class="blob-line-num js-line-number" data-line-number="1656"></td>
        <td id="LC1656" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1657" class="blob-line-num js-line-number" data-line-number="1657"></td>
        <td id="LC1657" class="blob-line-code js-file-line">    <span class="n">responseFirstHighestJetPt_Zinc1jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstHighestJetPt_Zinc1jet</span><span class="p">,</span>        <span class="n">genFirstHighestJetPt_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1658" class="blob-line-num js-line-number" data-line-number="1658"></td>
        <td id="LC1658" class="blob-line-code js-file-line">    <span class="n">responseFirstHighestJetPt_Zinc2jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstHighestJetPt_Zinc2jet</span><span class="p">,</span>        <span class="n">genFirstHighestJetPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1659" class="blob-line-num js-line-number" data-line-number="1659"></td>
        <td id="LC1659" class="blob-line-code js-file-line">    <span class="n">responseFirstHighestJetPt_Zinc3jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstHighestJetPt_Zinc3jet</span><span class="p">,</span>        <span class="n">genFirstHighestJetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1660" class="blob-line-num js-line-number" data-line-number="1660"></td>
        <td id="LC1660" class="blob-line-code js-file-line">    <span class="n">responseFirstHighestJetPt_Zinc4jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstHighestJetPt_Zinc4jet</span><span class="p">,</span>        <span class="n">genFirstHighestJetPt_Zinc4jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1661" class="blob-line-num js-line-number" data-line-number="1661"></td>
        <td id="LC1661" class="blob-line-code js-file-line">    <span class="n">responseFirstHighestJetPt_Zinc5jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstHighestJetPt_Zinc5jet</span><span class="p">,</span>        <span class="n">genFirstHighestJetPt_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1662" class="blob-line-num js-line-number" data-line-number="1662"></td>
        <td id="LC1662" class="blob-line-code js-file-line">    <span class="n">responseFirstHighestJetPt_Zinc6jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">FirstHighestJetPt_Zinc6jet</span><span class="p">,</span>        <span class="n">genFirstHighestJetPt_Zinc6jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1663" class="blob-line-num js-line-number" data-line-number="1663"></td>
        <td id="LC1663" class="blob-line-code js-file-line">    <span class="n">responseSecondHighestJetPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondHighestJetPt_Zinc2jet</span><span class="p">,</span>       <span class="n">genSecondHighestJetPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1664" class="blob-line-num js-line-number" data-line-number="1664"></td>
        <td id="LC1664" class="blob-line-code js-file-line">    <span class="n">responseSecondHighestJetPt_Zinc3jet</span> <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondHighestJetPt_Zinc3jet</span><span class="p">,</span>       <span class="n">genSecondHighestJetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1665" class="blob-line-num js-line-number" data-line-number="1665"></td>
        <td id="LC1665" class="blob-line-code js-file-line">    <span class="n">responseSecondHighestJetPt_Zinc4jet</span> <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondHighestJetPt_Zinc4jet</span><span class="p">,</span>       <span class="n">genSecondHighestJetPt_Zinc4jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1666" class="blob-line-num js-line-number" data-line-number="1666"></td>
        <td id="LC1666" class="blob-line-code js-file-line">    <span class="n">responseSecondHighestJetPt_Zinc5jet</span> <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondHighestJetPt_Zinc5jet</span><span class="p">,</span>       <span class="n">genSecondHighestJetPt_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1667" class="blob-line-num js-line-number" data-line-number="1667"></td>
        <td id="LC1667" class="blob-line-code js-file-line">    <span class="n">responseSecondHighestJetPt_Zinc6jet</span> <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SecondHighestJetPt_Zinc6jet</span><span class="p">,</span>       <span class="n">genSecondHighestJetPt_Zinc6jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1668" class="blob-line-num js-line-number" data-line-number="1668"></td>
        <td id="LC1668" class="blob-line-code js-file-line">    <span class="n">responseThirdHighestJetPt_Zinc3jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdHighestJetPt_Zinc3jet</span><span class="p">,</span>        <span class="n">genThirdHighestJetPt_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1669" class="blob-line-num js-line-number" data-line-number="1669"></td>
        <td id="LC1669" class="blob-line-code js-file-line">    <span class="n">responseThirdHighestJetPt_Zinc4jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdHighestJetPt_Zinc4jet</span><span class="p">,</span>        <span class="n">genThirdHighestJetPt_Zinc4jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1670" class="blob-line-num js-line-number" data-line-number="1670"></td>
        <td id="LC1670" class="blob-line-code js-file-line">    <span class="n">responseThirdHighestJetPt_Zinc5jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdHighestJetPt_Zinc5jet</span><span class="p">,</span>        <span class="n">genThirdHighestJetPt_Zinc5jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1671" class="blob-line-num js-line-number" data-line-number="1671"></td>
        <td id="LC1671" class="blob-line-code js-file-line">    <span class="n">responseThirdHighestJetPt_Zinc6jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">ThirdHighestJetPt_Zinc6jet</span><span class="p">,</span>        <span class="n">genThirdHighestJetPt_Zinc6jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1672" class="blob-line-num js-line-number" data-line-number="1672"></td>
        <td id="LC1672" class="blob-line-code js-file-line">    <span class="n">responseSpTJets_Zexc2jet</span>            <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SpTJets_Zexc2jet</span><span class="p">,</span>                  <span class="n">genSpTJets_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1673" class="blob-line-num js-line-number" data-line-number="1673"></td>
        <td id="LC1673" class="blob-line-code js-file-line">    <span class="n">responseSpTJets_Zinc2jet</span>            <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SpTJets_Zinc2jet</span><span class="p">,</span>                  <span class="n">genSpTJets_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1674" class="blob-line-num js-line-number" data-line-number="1674"></td>
        <td id="LC1674" class="blob-line-code js-file-line">    <span class="n">responseBestSpTJets_Zinc2jet</span>        <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestSpTJets_Zinc2jet</span><span class="p">,</span>              <span class="n">genBestSpTJets_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1675" class="blob-line-num js-line-number" data-line-number="1675"></td>
        <td id="LC1675" class="blob-line-code js-file-line">    <span class="n">responseSpTJets_LowPt_Zexc2jet</span>      <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SpTJets_LowPt_Zexc2jet</span><span class="p">,</span>            <span class="n">genSpTJets_LowPt_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1676" class="blob-line-num js-line-number" data-line-number="1676"></td>
        <td id="LC1676" class="blob-line-code js-file-line">    <span class="n">responseSpTJets_LowPt_Zinc2jet</span>      <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SpTJets_LowPt_Zinc2jet</span><span class="p">,</span>            <span class="n">genSpTJets_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1677" class="blob-line-num js-line-number" data-line-number="1677"></td>
        <td id="LC1677" class="blob-line-code js-file-line">    <span class="n">responseBestSpTJets_LowPt_Zinc2jet</span>  <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestSpTJets_LowPt_Zinc2jet</span><span class="p">,</span>        <span class="n">genBestSpTJets_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1678" class="blob-line-num js-line-number" data-line-number="1678"></td>
        <td id="LC1678" class="blob-line-code js-file-line">    <span class="n">responseSpT_Zexc2jet</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SpT_Zexc2jet</span><span class="p">,</span>                      <span class="n">genSpT_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1679" class="blob-line-num js-line-number" data-line-number="1679"></td>
        <td id="LC1679" class="blob-line-code js-file-line">    <span class="n">responseSpT_Zinc2jet</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SpT_Zinc2jet</span><span class="p">,</span>                      <span class="n">genSpT_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1680" class="blob-line-num js-line-number" data-line-number="1680"></td>
        <td id="LC1680" class="blob-line-code js-file-line">    <span class="n">responseBestSpT_Zinc2jet</span>            <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestSpT_Zinc2jet</span><span class="p">,</span>                  <span class="n">genBestSpT_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1681" class="blob-line-num js-line-number" data-line-number="1681"></td>
        <td id="LC1681" class="blob-line-code js-file-line">    <span class="n">responseSpT_LowPt_Zexc2jet</span>          <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SpT_LowPt_Zexc2jet</span><span class="p">,</span>                <span class="n">genSpT_LowPt_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1682" class="blob-line-num js-line-number" data-line-number="1682"></td>
        <td id="LC1682" class="blob-line-code js-file-line">    <span class="n">responseSpT_LowPt_Zinc2jet</span>          <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SpT_LowPt_Zinc2jet</span><span class="p">,</span>                <span class="n">genSpT_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1683" class="blob-line-num js-line-number" data-line-number="1683"></td>
        <td id="LC1683" class="blob-line-code js-file-line">    <span class="n">responseBestSpT_LowPt_Zinc2jet</span>      <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestSpT_LowPt_Zinc2jet</span><span class="p">,</span>            <span class="n">genBestSpT_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1684" class="blob-line-num js-line-number" data-line-number="1684"></td>
        <td id="LC1684" class="blob-line-code js-file-line">    <span class="n">responsedPhiJets_Zexc2jet</span>           <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">dPhiJets_Zexc2jet</span><span class="p">,</span>                 <span class="n">gendPhiJets_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1685" class="blob-line-num js-line-number" data-line-number="1685"></td>
        <td id="LC1685" class="blob-line-code js-file-line">    <span class="n">responsedPhiJets_Zinc2jet</span>           <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">dPhiJets_Zinc2jet</span><span class="p">,</span>                 <span class="n">gendPhiJets_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1686" class="blob-line-num js-line-number" data-line-number="1686"></td>
        <td id="LC1686" class="blob-line-code js-file-line">    <span class="n">responseBestdPhiJets_Zinc2jet</span>       <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestdPhiJets_Zinc2jet</span><span class="p">,</span>             <span class="n">genBestdPhiJets_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1687" class="blob-line-num js-line-number" data-line-number="1687"></td>
        <td id="LC1687" class="blob-line-code js-file-line">    <span class="n">responsedPhiJets_LowPt_Zexc2jet</span>     <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">dPhiJets_LowPt_Zexc2jet</span><span class="p">,</span>           <span class="n">gendPhiJets_LowPt_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1688" class="blob-line-num js-line-number" data-line-number="1688"></td>
        <td id="LC1688" class="blob-line-code js-file-line">    <span class="n">responsedPhiJets_LowPt_Zinc2jet</span>     <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">dPhiJets_LowPt_Zinc2jet</span><span class="p">,</span>           <span class="n">gendPhiJets_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1689" class="blob-line-num js-line-number" data-line-number="1689"></td>
        <td id="LC1689" class="blob-line-code js-file-line">    <span class="n">responseBestdPhiJets_LowPt_Zinc2jet</span> <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestdPhiJets_LowPt_Zinc2jet</span><span class="p">,</span>       <span class="n">genBestdPhiJets_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1690" class="blob-line-num js-line-number" data-line-number="1690"></td>
        <td id="LC1690" class="blob-line-code js-file-line">    <span class="n">responsePHI_Zexc2jet</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">PHI_Zexc2jet</span><span class="p">,</span>                      <span class="n">genPHI_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1691" class="blob-line-num js-line-number" data-line-number="1691"></td>
        <td id="LC1691" class="blob-line-code js-file-line">    <span class="n">responsePHI_Zinc2jet</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">PHI_Zinc2jet</span><span class="p">,</span>                      <span class="n">genPHI_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1692" class="blob-line-num js-line-number" data-line-number="1692"></td>
        <td id="LC1692" class="blob-line-code js-file-line">    <span class="n">responseBestPHI_Zinc2jet</span>            <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestPHI_Zinc2jet</span><span class="p">,</span>                  <span class="n">genBestPHI_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1693" class="blob-line-num js-line-number" data-line-number="1693"></td>
        <td id="LC1693" class="blob-line-code js-file-line">    <span class="n">responsePHI_LowPt_Zexc2jet</span>          <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">PHI_LowPt_Zexc2jet</span><span class="p">,</span>                <span class="n">genPHI_LowPt_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1694" class="blob-line-num js-line-number" data-line-number="1694"></td>
        <td id="LC1694" class="blob-line-code js-file-line">    <span class="n">responsePHI_LowPt_Zinc2jet</span>          <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">PHI_LowPt_Zinc2jet</span><span class="p">,</span>                <span class="n">genPHI_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1695" class="blob-line-num js-line-number" data-line-number="1695"></td>
        <td id="LC1695" class="blob-line-code js-file-line">    <span class="n">responseBestPHI_LowPt_Zinc2jet</span>      <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestPHI_LowPt_Zinc2jet</span><span class="p">,</span>            <span class="n">genBestPHI_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1696" class="blob-line-num js-line-number" data-line-number="1696"></td>
        <td id="LC1696" class="blob-line-code js-file-line">    <span class="n">responsePHI_T_Zexc2jet</span>              <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">PHI_T_Zexc2jet</span><span class="p">,</span>                    <span class="n">genPHI_T_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1697" class="blob-line-num js-line-number" data-line-number="1697"></td>
        <td id="LC1697" class="blob-line-code js-file-line">    <span class="n">responsePHI_T_Zinc2jet</span>              <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">PHI_T_Zinc2jet</span><span class="p">,</span>                    <span class="n">genPHI_T_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1698" class="blob-line-num js-line-number" data-line-number="1698"></td>
        <td id="LC1698" class="blob-line-code js-file-line">    <span class="n">responseBestPHI_T_Zinc2jet</span>          <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestPHI_T_Zinc2jet</span><span class="p">,</span>                <span class="n">genBestPHI_T_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1699" class="blob-line-num js-line-number" data-line-number="1699"></td>
        <td id="LC1699" class="blob-line-code js-file-line">    <span class="n">responsePHI_T_LowPt_Zexc2jet</span>        <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">PHI_T_LowPt_Zexc2jet</span><span class="p">,</span>              <span class="n">genPHI_T_LowPt_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1700" class="blob-line-num js-line-number" data-line-number="1700"></td>
        <td id="LC1700" class="blob-line-code js-file-line">    <span class="n">responsePHI_T_LowPt_Zinc2jet</span>        <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">PHI_T_LowPt_Zinc2jet</span><span class="p">,</span>              <span class="n">genPHI_T_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1701" class="blob-line-num js-line-number" data-line-number="1701"></td>
        <td id="LC1701" class="blob-line-code js-file-line">    <span class="n">responseBestPHI_T_LowPt_Zinc2jet</span>    <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestPHI_T_LowPt_Zinc2jet</span><span class="p">,</span>          <span class="n">genBestPHI_T_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1702" class="blob-line-num js-line-number" data-line-number="1702"></td>
        <td id="LC1702" class="blob-line-code js-file-line">    <span class="n">responseSPhi_Zexc2jet</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SPhi_Zexc2jet</span><span class="p">,</span>                     <span class="n">genSPhi_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1703" class="blob-line-num js-line-number" data-line-number="1703"></td>
        <td id="LC1703" class="blob-line-code js-file-line">    <span class="n">responseSPhi_Zinc2jet</span>               <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SPhi_Zinc2jet</span><span class="p">,</span>                     <span class="n">genSPhi_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1704" class="blob-line-num js-line-number" data-line-number="1704"></td>
        <td id="LC1704" class="blob-line-code js-file-line">    <span class="n">responsedEtaJets_Zexc2jet</span>           <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">dEtaJets_Zexc2jet</span><span class="p">,</span>                 <span class="n">gendEtaJets_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1705" class="blob-line-num js-line-number" data-line-number="1705"></td>
        <td id="LC1705" class="blob-line-code js-file-line">    <span class="n">responsedEtaJets_Zinc2jet</span>           <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">dEtaJets_Zinc2jet</span><span class="p">,</span>                 <span class="n">gendEtaJets_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1706" class="blob-line-num js-line-number" data-line-number="1706"></td>
        <td id="LC1706" class="blob-line-code js-file-line">    <span class="n">responseBestSPhi_Zinc2jet</span>           <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestSPhi_Zinc2jet</span><span class="p">,</span>                 <span class="n">genBestSPhi_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1707" class="blob-line-num js-line-number" data-line-number="1707"></td>
        <td id="LC1707" class="blob-line-code js-file-line">    <span class="n">responseSPhi_LowPt_Zexc2jet</span>         <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SPhi_LowPt_Zexc2jet</span><span class="p">,</span>               <span class="n">genSPhi_LowPt_Zexc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1708" class="blob-line-num js-line-number" data-line-number="1708"></td>
        <td id="LC1708" class="blob-line-code js-file-line">    <span class="n">responseSPhi_LowPt_Zinc2jet</span>         <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">SPhi_LowPt_Zinc2jet</span><span class="p">,</span>               <span class="n">genSPhi_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1709" class="blob-line-num js-line-number" data-line-number="1709"></td>
        <td id="LC1709" class="blob-line-code js-file-line">    <span class="n">responseBestSPhi_LowPt_Zinc2jet</span>     <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">BestSPhi_LowPt_Zinc2jet</span><span class="p">,</span>           <span class="n">genBestSPhi_LowPt_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1710" class="blob-line-num js-line-number" data-line-number="1710"></td>
        <td id="LC1710" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1711" class="blob-line-num js-line-number" data-line-number="1711"></td>
        <td id="LC1711" class="blob-line-code js-file-line">    <span class="c1">// ratio plots  </span></td>
      </tr>
      <tr>
        <td id="L1712" class="blob-line-num js-line-number" data-line-number="1712"></td>
        <td id="LC1712" class="blob-line-code js-file-line">    <span class="n">responseRatioJetPt21</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">RatioJetPt21_Zinc2jet</span><span class="p">,</span>               <span class="n">genRatioJetPt21_Zinc2jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1713" class="blob-line-num js-line-number" data-line-number="1713"></td>
        <td id="LC1713" class="blob-line-code js-file-line">    <span class="n">responseRatioJetPt32</span>                <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">RatioJetPt32_Zinc3jet</span><span class="p">,</span>               <span class="n">genRatioJetPt32_Zinc3jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1714" class="blob-line-num js-line-number" data-line-number="1714"></td>
        <td id="LC1714" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1715" class="blob-line-num js-line-number" data-line-number="1715"></td>
        <td id="LC1715" class="blob-line-code js-file-line">    <span class="c1">// vector boson and single jet</span></td>
      </tr>
      <tr>
        <td id="L1716" class="blob-line-num js-line-number" data-line-number="1716"></td>
        <td id="LC1716" class="blob-line-code js-file-line">    <span class="n">responsedEtaBosonJet_Zexc1</span>          <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">dEtaBosonJet_Zexc1jet</span><span class="p">,</span>            <span class="n">gendEtaBosonJet_Zexc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1717" class="blob-line-num js-line-number" data-line-number="1717"></td>
        <td id="LC1717" class="blob-line-code js-file-line">    <span class="n">responsedEtaBosonJet_Zinc1</span>          <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span><span class="n">dEtaBosonJet_Zinc1jet</span><span class="p">,</span>            <span class="n">gendEtaBosonJet_Zinc1jet</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1718" class="blob-line-num js-line-number" data-line-number="1718"></td>
        <td id="LC1718" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1719" class="blob-line-num js-line-number" data-line-number="1719"></td>
        <td id="LC1719" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1720" class="blob-line-num js-line-number" data-line-number="1720"></td>
        <td id="LC1720" class="blob-line-code js-file-line">    <span class="c1">// for 2D unfolding --- create 1D histograms for different rapidity ranges</span></td>
      </tr>
      <tr>
        <td id="L1721" class="blob-line-num js-line-number" data-line-number="1721"></td>
        <td id="LC1721" class="blob-line-code js-file-line">    <span class="n">NbinsEta2Dtest</span> <span class="o">=</span> <span class="n">NbinsEta2D</span> <span class="p">;</span></td>
      </tr>
      <tr>
        <td id="L1722" class="blob-line-num js-line-number" data-line-number="1722"></td>
        <td id="LC1722" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">j_pT_range1</span><span class="p">[</span><span class="n">NbinsEta2D</span><span class="p">]</span><span class="o">=</span><span class="p">{</span><span class="mf">30.</span><span class="p">,</span><span class="mf">50.</span><span class="p">,</span><span class="mf">70.</span><span class="p">,</span><span class="mf">100.</span><span class="p">,</span><span class="mf">130.</span><span class="p">,</span><span class="mf">170.</span><span class="p">,</span><span class="mf">220.</span><span class="p">,</span><span class="mf">350.</span><span class="p">,</span><span class="mf">1000.</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L1723" class="blob-line-num js-line-number" data-line-number="1723"></td>
        <td id="LC1723" class="blob-line-code js-file-line">    <span class="kt">double</span> <span class="n">j_Y_range1</span><span class="p">[</span><span class="n">NbinsEta2D</span><span class="p">]</span><span class="o">=</span><span class="p">{</span><span class="mf">0.</span><span class="p">,</span><span class="mf">0.5</span><span class="p">,</span><span class="mf">1.0</span><span class="p">,</span><span class="mf">1.5</span><span class="p">,</span><span class="mf">2.0</span><span class="p">,</span><span class="mf">2.5</span><span class="p">,</span><span class="mf">3.0</span><span class="p">,</span><span class="mf">3.2</span><span class="p">,</span><span class="mf">4.7</span><span class="p">};</span></td>
      </tr>
      <tr>
        <td id="L1724" class="blob-line-num js-line-number" data-line-number="1724"></td>
        <td id="LC1724" class="blob-line-code js-file-line">    <span class="k">for</span> <span class="p">(</span> <span class="kt">int</span> <span class="n">i</span> <span class="o">=</span><span class="mi">0</span> <span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">NbinsEta2D</span>  <span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L1725" class="blob-line-num js-line-number" data-line-number="1725"></td>
        <td id="LC1725" class="blob-line-code js-file-line">        <span class="n">j_pT_range</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">j_pT_range1</span><span class="p">[</span><span class="n">i</span><span class="p">];</span></td>
      </tr>
      <tr>
        <td id="L1726" class="blob-line-num js-line-number" data-line-number="1726"></td>
        <td id="LC1726" class="blob-line-code js-file-line">        <span class="n">j_Y_range</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">j_Y_range1</span><span class="p">[</span><span class="n">i</span><span class="p">];</span></td>
      </tr>
      <tr>
        <td id="L1727" class="blob-line-num js-line-number" data-line-number="1727"></td>
        <td id="LC1727" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L1728" class="blob-line-num js-line-number" data-line-number="1728"></td>
        <td id="LC1728" class="blob-line-code js-file-line">    <span class="c1">/// setup leading jet hitograms and response</span></td>
      </tr>
      <tr>
        <td id="L1729" class="blob-line-num js-line-number" data-line-number="1729"></td>
        <td id="LC1729" class="blob-line-code js-file-line">    <span class="k">for</span> <span class="p">(</span> <span class="kt">int</span> <span class="n">i</span> <span class="o">=</span><span class="mi">0</span> <span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">NbinsEta2D</span> <span class="o">-</span> <span class="mi">1</span> <span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L1730" class="blob-line-num js-line-number" data-line-number="1730"></td>
        <td id="LC1730" class="blob-line-code js-file-line">        <span class="kt">char</span> <span class="n">name</span><span class="p">[</span><span class="mi">100</span><span class="p">];</span></td>
      </tr>
      <tr>
        <td id="L1731" class="blob-line-num js-line-number" data-line-number="1731"></td>
        <td id="LC1731" class="blob-line-code js-file-line">        <span class="kt">char</span> <span class="n">name1</span><span class="p">[</span><span class="mi">100</span><span class="p">];</span></td>
      </tr>
      <tr>
        <td id="L1732" class="blob-line-num js-line-number" data-line-number="1732"></td>
        <td id="LC1732" class="blob-line-code js-file-line">        <span class="n">sprintf</span><span class="p">(</span><span class="n">name</span><span class="p">,</span><span class="s">&quot;FirstJetPt_Zinc1jet_Eta_%i&quot;</span><span class="p">,</span><span class="n">i</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1733" class="blob-line-num js-line-number" data-line-number="1733"></td>
        <td id="LC1733" class="blob-line-code js-file-line">        <span class="n">sprintf</span><span class="p">(</span><span class="n">name1</span><span class="p">,</span><span class="s">&quot;1st jet p_{T} (N_{jets} #geq 1): Rap %i&quot;</span><span class="p">,</span> <span class="n">i</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1734" class="blob-line-num js-line-number" data-line-number="1734"></td>
        <td id="LC1734" class="blob-line-code js-file-line">        <span class="n">FirstJetPt_Zinc1jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">]</span><span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="n">name</span><span class="p">,</span> <span class="n">name1</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">NbinsEta2D</span> <span class="o">-</span> <span class="mi">1</span><span class="p">,</span> <span class="n">j_pT_range</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1735" class="blob-line-num js-line-number" data-line-number="1735"></td>
        <td id="LC1735" class="blob-line-code js-file-line">        <span class="n">sprintf</span><span class="p">(</span><span class="n">name</span><span class="p">,</span><span class="s">&quot;genFirstJetPt_Zinc1jet_Eta%i&quot;</span><span class="p">,</span><span class="n">i</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1736" class="blob-line-num js-line-number" data-line-number="1736"></td>
        <td id="LC1736" class="blob-line-code js-file-line">        <span class="n">sprintf</span><span class="p">(</span><span class="n">name1</span><span class="p">,</span><span class="s">&quot;gen: 1st jet p_{T} (N_{jets} #geq 1): Rap %i&quot;</span><span class="p">,</span> <span class="n">i</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1737" class="blob-line-num js-line-number" data-line-number="1737"></td>
        <td id="LC1737" class="blob-line-code js-file-line">        <span class="n">genFirstJetPt_Zinc1jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">]</span><span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="n">name</span><span class="p">,</span> <span class="n">name1</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{1}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">NbinsEta2D</span> <span class="o">-</span> <span class="mi">1</span><span class="p">,</span> <span class="n">j_pT_range</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1738" class="blob-line-num js-line-number" data-line-number="1738"></td>
        <td id="LC1738" class="blob-line-code js-file-line">        <span class="n">responseFirstJetPt_Zinc1jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span> <span class="n">FirstJetPt_Zinc1jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">],</span> <span class="n">genFirstJetPt_Zinc1jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1739" class="blob-line-num js-line-number" data-line-number="1739"></td>
        <td id="LC1739" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L1740" class="blob-line-num js-line-number" data-line-number="1740"></td>
        <td id="LC1740" class="blob-line-code js-file-line">    <span class="c1">// setup 2nd leading jet hitograms and response</span></td>
      </tr>
      <tr>
        <td id="L1741" class="blob-line-num js-line-number" data-line-number="1741"></td>
        <td id="LC1741" class="blob-line-code js-file-line">    <span class="k">for</span> <span class="p">(</span> <span class="kt">int</span> <span class="n">i</span> <span class="o">=</span><span class="mi">0</span> <span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">NbinsEta2D</span> <span class="o">-</span> <span class="mi">1</span> <span class="p">;</span> <span class="n">i</span><span class="o">++</span><span class="p">){</span></td>
      </tr>
      <tr>
        <td id="L1742" class="blob-line-num js-line-number" data-line-number="1742"></td>
        <td id="LC1742" class="blob-line-code js-file-line">        <span class="kt">char</span> <span class="n">name</span><span class="p">[</span><span class="mi">100</span><span class="p">];</span></td>
      </tr>
      <tr>
        <td id="L1743" class="blob-line-num js-line-number" data-line-number="1743"></td>
        <td id="LC1743" class="blob-line-code js-file-line">        <span class="kt">char</span> <span class="n">name1</span><span class="p">[</span><span class="mi">100</span><span class="p">];</span></td>
      </tr>
      <tr>
        <td id="L1744" class="blob-line-num js-line-number" data-line-number="1744"></td>
        <td id="LC1744" class="blob-line-code js-file-line">        <span class="n">sprintf</span><span class="p">(</span><span class="n">name</span><span class="p">,</span><span class="s">&quot;SecondJetPt_Zinc2jet_Eta_%i&quot;</span><span class="p">,</span><span class="n">i</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1745" class="blob-line-num js-line-number" data-line-number="1745"></td>
        <td id="LC1745" class="blob-line-code js-file-line">        <span class="n">sprintf</span><span class="p">(</span><span class="n">name1</span><span class="p">,</span><span class="s">&quot;2nd jet p_{T} (N_{jets} #geq 2): Rap %i&quot;</span><span class="p">,</span> <span class="n">i</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1746" class="blob-line-num js-line-number" data-line-number="1746"></td>
        <td id="LC1746" class="blob-line-code js-file-line">        <span class="n">SecondJetPt_Zinc2jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">]</span><span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="n">name</span><span class="p">,</span> <span class="n">name1</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">NbinsEta2D</span> <span class="o">-</span> <span class="mi">1</span><span class="p">,</span> <span class="n">j_pT_range</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1747" class="blob-line-num js-line-number" data-line-number="1747"></td>
        <td id="LC1747" class="blob-line-code js-file-line">        <span class="n">sprintf</span><span class="p">(</span><span class="n">name</span><span class="p">,</span><span class="s">&quot;genSecondJetPt_Zinc2jet_Eta%i&quot;</span><span class="p">,</span><span class="n">i</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1748" class="blob-line-num js-line-number" data-line-number="1748"></td>
        <td id="LC1748" class="blob-line-code js-file-line">        <span class="n">sprintf</span><span class="p">(</span><span class="n">name1</span><span class="p">,</span><span class="s">&quot;gen: 2nd jet p_{T} (N_{jets} #geq 2): Rap %i&quot;</span><span class="p">,</span> <span class="n">i</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1749" class="blob-line-num js-line-number" data-line-number="1749"></td>
        <td id="LC1749" class="blob-line-code js-file-line">        <span class="n">genSecondJetPt_Zinc2jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">]</span><span class="o">=</span> <span class="n">newTH1D</span><span class="p">(</span><span class="n">name</span><span class="p">,</span> <span class="n">name1</span><span class="p">,</span>           <span class="s">&quot;p_{T}(j_{2}) [GeV]&quot;</span><span class="p">,</span>     <span class="n">NbinsEta2D</span> <span class="o">-</span> <span class="mi">1</span><span class="p">,</span> <span class="n">j_pT_range</span><span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1750" class="blob-line-num js-line-number" data-line-number="1750"></td>
        <td id="LC1750" class="blob-line-code js-file-line">        <span class="n">responseSecondJetPt_Zinc2jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="n">newResp</span><span class="p">(</span> <span class="n">SecondJetPt_Zinc2jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">],</span> <span class="n">genSecondJetPt_Zinc2jet_Eta</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="p">);</span></td>
      </tr>
      <tr>
        <td id="L1751" class="blob-line-num js-line-number" data-line-number="1751"></td>
        <td id="LC1751" class="blob-line-code js-file-line">    <span class="p">}</span></td>
      </tr>
      <tr>
        <td id="L1752" class="blob-line-num js-line-number" data-line-number="1752"></td>
        <td id="LC1752" class="blob-line-code js-file-line">
</td>
      </tr>
      <tr>
        <td id="L1753" class="blob-line-num js-line-number" data-line-number="1753"></td>
        <td id="LC1753" class="blob-line-code js-file-line"><span class="p">}</span></td>
      </tr>
</table>

  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/" aria-label="Homepage">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.03165s from github-fe139-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-suggester-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="fullscreen-contents js-fullscreen-contents js-suggester-field" placeholder=""></textarea>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-x close js-ajax-error-dismiss" aria-label="Dismiss error"></a>
      Something went wrong with that request. Please try again.
    </div>


      <script crossorigin="anonymous" src="https://assets-cdn.github.com/assets/frameworks-12d5fda141e78e513749dddbc56445fe172cbd9a.js" type="text/javascript"></script>
      <script async="async" crossorigin="anonymous" src="https://assets-cdn.github.com/assets/github-f8cf379f177c2fd3562514979aef2b0ea1ccc9a2.js" type="text/javascript"></script>
      
      
        <script async src="https://www.google-analytics.com/analytics.js"></script>
  </body>
</html>

